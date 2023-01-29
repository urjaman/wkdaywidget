/* MicroCrystal RV-3032-C7 */
#include "main.h"
#include "time.h"
#include "i2c.h"
#include "rtc.h"

#if 0
#include "uart.h"
#include "console.h"
#define D(x) uart_send(x)
#define DH(x) luint2outdual(x)
#else
#define D(x) (void)(x)
#define DH(x) (void)(x)
#endif

#define RV3032C7_I2C_ADDR (0x51<<1)
#define RTC_I2C_ADDR RV3032C7_I2C_ADDR

static uint8_t readbcd(uint8_t bcd) {
	return (bcd>>4)*10+(bcd&0xF);
}
static uint8_t writebcd(uint8_t bin) {
	uint8_t bcd = bin%10;
	bcd |= (bin/10) << 4;
	return bcd;
}

static uint8_t rtc_is_ok=0;

// 0 = OK, nonzero = not ok
uint8_t rtc_read(struct mtm* tm) {
	uint8_t buf[10];
	/* Timekeeping registers */
	if (i2c_read_regs(RTC_I2C_ADDR,1,7,buf)) {
		rtc_is_ok=0;
		return 1; // Not OK
	}
	/* Two bytes of user RAM for century and check */
	if (i2c_read_regs(RTC_I2C_ADDR,0x40,2,buf+7)) {
		rtc_is_ok=0;
		return 1;
	}
	/* the status byte */
	if (i2c_read_regs(RTC_I2C_ADDR, 0xD,1,buf+9)) {
		rtc_is_ok=0;
		return 1;
	}
	if (buf[9]&0x03) { // POR or VLF
		rtc_is_ok = 0;
		return 2; // VL, not OK
	}
	tm->sec = readbcd(buf[0]);
	tm->min = readbcd(buf[1]&0x7F);
	tm->hour = readbcd(buf[2]&0x3F);
	tm->year = readbcd(buf[6]);
	tm->month = readbcd(buf[5]&0x1F);
	tm->day = readbcd(buf[4]&0x3F);
	uint8_t chkcentury = buf[8] ^ 0xFF;
	if ((buf[7]) && (buf[7] <= 2) && (buf[7] == chkcentury)) {
		/* Use first byte of SRAM for century -
		 * it will not work automatically, but atleast
		 * we should remember it correctly if set. */
		tm->year += (buf[7] * 100);
	}
	rtc_is_ok = 1;
	return 0; // OK
}


void rtc_write(struct mtm* tm) {
	uint8_t buf[10];
	buf[0] = writebcd(tm->sec);
	buf[1] = writebcd(tm->min);
	buf[2] = writebcd(tm->hour);
	buf[4] = writebcd(tm->day);
	buf[3] = 1; // WeekDay, unused.
	buf[5] = writebcd(tm->month);
	buf[6] = writebcd(tm->year % 100);
	// a bit of a checksum so the century doesnt get used accidentally
	buf[7] = tm->year/100;
	buf[8] = (tm->year/100) ^ 0xFF;
	buf[9] = 0; /* Clear out all the IRQ flags */

	if (i2c_write_regs(RTC_I2C_ADDR,1,7,buf)) {
		rtc_is_ok = 0;
		return; // Not OK
	}

	if (i2c_write_regs(RTC_I2C_ADDR,0x40,2,buf+7)) {
		rtc_is_ok = 0;
		return; // Not OK
	}

	if (i2c_write_regs(RTC_I2C_ADDR,0xD,1,buf+9)) {
		rtc_is_ok = 0;
		return; // Not OK
	}
	rtc_is_ok = 1;
	return;
}

int16_t rtc_temp(void) {
	int16_t r1, r2;
	uint8_t buf[2];
	if (i2c_read_regs(RTC_I2C_ADDR, 0xE, 2, buf)) {
		return -2048;
	}
	r2 = (buf[1] << 4) | (buf[0] >> 4);
	do {
		r1 = r2;
		if (i2c_read_regs(RTC_I2C_ADDR, 0xE, 2, buf)) {
			return -2048;
		}
		r2 = (buf[1] << 4) | (buf[0] >> 4);
	} while (r1 != r2);
	if (r1 & 0x800) r1 |= 0xF000;
	return r1;
}


uint8_t rtc_valid(void) {
	return rtc_is_ok;
}

static uint8_t rtc_wait_eebusy(void) {
	uint8_t eebusy = 0;
	do {
		if (eebusy)
			_delay_ms(10);
		if (i2c_read_regs(RTC_I2C_ADDR, 0xE, 1, &eebusy)) {
			return 1;
		}
		eebusy &= 0x4;
	} while (eebusy);
	return 0;
}

uint8_t rtc_init(void) {
/* 450*8192 = 3686400 Hz */
#define HFD 450
	const uint8_t ee_mask[4] = {
		0xFF, /* PMU */
		0xC0, /* Offset: Ignore change in the aging offset */
		0xFF, /* Clkout 1 */
		0xFF  /* Clkout 2 */
		};
	const uint8_t ee_settings[4] = {
		0x20, /* BSM 10 (LSM), others default (0x23 for 4.4V trickle charge) */
		0x00, /* Defaults ok here (no interrupts, dont touch aging offset). */
		HFD & 0xFF,
		0x80 | ((HFD >> 8) & 0x1F) /* Select high frequency output at 3.6864Mhz */
		};
	/* Control 1 X must be set to 1, regardless. */
	const uint8_t ctrl1_default = 0x20;
	uint8_t buf[4];
	uint8_t diff;

	/* Perform dummy I2C operation to make sure the RTC knows what the
	 * state of the I2C bus is. */
	D('1');
	if (i2c_start(2)==0) {
	 	i2c_stop();
	}

	D('2');
	/* Wait until the eebusy bit is cleared */
	/* This is to make sure the contents we're about to read are ok. */
	if (rtc_wait_eebusy())
		return 1;

	D('3');

	/* Read the EEPROM regs we care about. */
	if (i2c_read_regs(RTC_I2C_ADDR, 0xC0,4,buf))
		return 1;

	D('4');

	/* Compare and adjust */
	diff = 0;
	for (uint8_t i=0;i<4;i++) {
		DH(ee_settings[i]);
		if ((buf[i] & ee_mask[i]) != ee_settings[i]) {
			D('D');
			DH((i << 8) | buf[i]);
			
			diff = 1;
			buf[i] = (buf[i] & ~ee_mask[i]) | ee_settings[i];
		}
	}
	D('5');

	if (diff) {
		uint8_t vfy[4];
		const uint8_t ctrl1_eerd = ctrl1_default | 0x4;

		/* EERD */
		if (i2c_write_reg(RTC_I2C_ADDR, 0x10, ctrl1_eerd))
			return 1;

	D('6');

		/* This is in case a refresh just happened to start. */
		if (rtc_wait_eebusy())
			return 1;
	D('7');


		if (i2c_write_regs(RTC_I2C_ADDR, 0xC0, 4, buf))
			return 1;
	D('u');

		if (i2c_read_regs(RTC_I2C_ADDR, 0xC0, 4, vfy))
			return 1;

		for (uint8_t i=0;i<4;i++)
		if (vfy[i] != buf[i]) {
			D('F');
			DH(((long)i<<16) | (vfy[i]<<8) | buf[i]);
			return 1;
		}

	D('8');

		/* EECMD = 11h, Update EEPROM from RAM */
		if (i2c_write_reg(RTC_I2C_ADDR, 0x3F, 0x11))
			return 1;

	D('9');

		/* Wait for the operation to complete. */
		if (rtc_wait_eebusy())
			return 1;
	D('G');

	}

	/* Regardless, set Ctrl1 (and disable EERD) */
	if (i2c_write_reg(RTC_I2C_ADDR, 0x10, ctrl1_default))
		return 1;
	D('z');

	/* Wait for the clock to be stable, before we let timer consider
	 * switching to it. */
	_delay_ms(5);

	D('g');
	return 0;
}
