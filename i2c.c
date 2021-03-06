/*************************************************************************
* Title:    I2C master library using hardware TWI interface
* Author:   Peter Fleury <pfleury@gmx.ch>  http://jump.to/fleury
* File:     $Id: twimaster.c,v 1.3 2005/07/02 11:14:21 Peter Exp $
* Software: AVR-GCC 3.4.3 / avr-libc 1.2.3
* Target:   any AVR device with hardware TWI 
* Usage:    API compatible with I2C Software Library i2cmaster.h
**************************************************************************/
/* Hacked By Urjaman */

#include "main.h"
#include "i2c.h"
#include <util/twi.h>
/* I2C clock in Hz - DS1307 is max 100Khz */
#define SCL_CLOCK  100000L

/*************************************************************************
 Initialization of the I2C bus interface. Need to be called only once
*************************************************************************/
void i2c_init(void) {
	/* initialize TWI clock: 100 kHz clock, TWPS = 0 => prescaler = 1 */
	TWSR = 0;                         /* no prescaler */
	TWBR = ((F_CPU/SCL_CLOCK)-16)/2;  /* must be > 10 for stable operation */
}

/*************************************************************************	
  Issues a start condition and sends address and transfer direction.
  return 0 = device accessible, 1= failed to access device (start)
  2= device doesnt ack address. You never need to i2c_stop after failed start.
*************************************************************************/
unsigned char i2c_start(unsigned char address) {
	uint8_t   twst;
	// send START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait until transmission completed
	while(!(TWCR & (1<<TWINT)));
	// check value of TWI Status Register. Mask prescaler bits.
	twst = TW_STATUS & 0xF8;
	if ( (twst != TW_START) && (twst != TW_REP_START)) return 1;
	// send device address
	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wail until transmission completed and ACK/NACK has been received
	while(!(TWCR & (1<<TWINT)));
	// check value of TWI Status Register. Mask prescaler bits.
	twst = TW_STATUS & 0xF8;
	if ( (twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK) ) {
		i2c_stop();
		return 2;
	}
	return 0;
}

/*************************************************************************
 Issues a repeated start condition and sends address and transfer direction 
 Input:   address and transfer direction of I2C device
 Return:  0 device accessible
          1 failed to access device
*************************************************************************/
unsigned char i2c_rep_start(unsigned char address) {
	return i2c_start( address );
}

/*************************************************************************
 Terminates the data transfer and releases the I2C bus
*************************************************************************/
void i2c_stop(void) {
	/* send stop condition */
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	// wait until stop condition is executed and bus released
	while(TWCR & (1<<TWSTO));
}

/*************************************************************************
  Send one byte to I2C device
  Input:    byte to be transfered
  Return:   0 write successful 
            1 write failed
*************************************************************************/
unsigned char i2c_write( unsigned char data ) {
	uint8_t twst;
	// send data to the previously addressed device
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait until transmission completed
	while(!(TWCR & (1<<TWINT)));
	// check value of TWI Status Register. Mask prescaler bits
	twst = TW_STATUS & 0xF8;
	if( twst != TW_MT_DATA_ACK) return 1;
	return 0;
}

/*************************************************************************
 Read one byte from the I2C device, request more data from device 
 Return:  byte read from I2C device
*************************************************************************/
unsigned char i2c_readAck(void) {
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(!(TWCR & (1<<TWINT)));    
	return TWDR;
}

/*************************************************************************
 Read one byte from the I2C device, read is followed by a stop condition 
 Return:  byte read from I2C device
*************************************************************************/
unsigned char i2c_readNak(void) {
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	return TWDR;
}

/************************************************************************
 Perform register-based I2C device operations. This reads cnt regs
 starting with reg into buf from dev. Return values per i2c_start().
************************************************************************/
uint8_t i2c_read_regs(uint8_t dev, uint8_t reg, uint8_t cnt, uint8_t* buf) {
	uint8_t x;
	if ((x = i2c_start(dev&0xFE))) return x;
	if (i2c_write(reg)) goto fail_exit;
	if ((x = i2c_rep_start(dev|0x01))) return x;
	uint8_t offset=0;
	while (cnt>1) {
		buf[offset++] = i2c_readAck();
		cnt--;
	}
	if (cnt) buf[offset] = i2c_readNak();
	i2c_stop();
	return 0;
fail_exit:
	i2c_stop();
	return 1;
}


/************************************************************************
 Perform register-based I2C device operations. This writes cnt regs
 starting with reg into dev from buf. Return values per i2c_start().
************************************************************************/
uint8_t i2c_write_regs(uint8_t dev, uint8_t reg, uint8_t cnt, uint8_t* buf) {
	uint8_t x;
	if ((x = i2c_start(dev&0xFE))) return x;
	if (i2c_write(reg)) goto fail_exit;
	for (uint8_t i=0;i<cnt;i++) {
		if (i2c_write(buf[i])) goto fail_exit;
	}
	i2c_stop();
	return 0;
fail_exit:
	i2c_stop();
	return 1;
}


/* Simple 1-byte transfer versions of the above functions. */
uint8_t i2c_read_reg(uint8_t dev, uint8_t reg, uint8_t *val) {
	return i2c_read_regs(dev,reg,1,val);
}


uint8_t i2c_write_reg(uint8_t dev, uint8_t reg, uint8_t val) {
	return i2c_write_regs(dev,reg,1,&val);
}
