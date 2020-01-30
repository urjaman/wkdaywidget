#include "main.h"
#include "timer.h"
#include "dsp16seg.h"
#include "buttons.h"
#include "ui.h"

// English version in case you want it:
//const char wkdaystr[] PROGMEM = "MOTUWETHFRSASU";

const char wkdaystr[] PROGMEM =   "MATIKETOPELASU";

static void update_wkday(void) {
	char str[4];
	if (timer_time_isvalid()) {
		uint24_t day;
		struct mtm t;
		timer_get_time(&t);
		day = mtm2lindate(&t);
		uint8_t wdo = ((day + EPOCH_DAY_OF_WEEK) % 7) * 2;
		str[0] = pgm_read_byte(wkdaystr + wdo);
		str[1] = pgm_read_byte(wkdaystr + wdo + 1);
		str[2] = t.hour >= 12 ? '.' : 0;
		str[3] = 0;
	} else {
		str[0] = '.';
		str[1] = '.';
		str[2] = 0;
	}
	dsp16seg_settext(str);
}


static void ui_scroll_str(const char* str) {
	char lstr[5];
	uint8_t ml = strlen(str);
	uint8_t off = 0;
	uint8_t dl = 0;
	do {
		uint8_t cl = ml-off < 4 ? ml-off : 4;
		memcpy(lstr, str+off, cl);
		lstr[cl] = 0;
		dl = dsp16seg_settext(lstr);
		for (uint8_t d=0;d<5;d++) {
			timer_delay_ms(50);
			mini_mainloop();
			if (buttons_get()) return;
		}
		off++;
		if (lstr[1] == '.') off++;
	} while (((off-1)+dl) < ml);
}

static char uiscroll_buf[48];
static void ui_scroll_str_P(const PGM_P str) {
	strcpy_P(uiscroll_buf, str);
	ui_scroll_str(uiscroll_buf);
}

static void twodigits(char *c, uint8_t v) {
	c[0] = (v/10) | 0x30;
	c[1] = (v%10) | 0x30;
}

static void date_scroller(void) {
	// 1234567890123456
	// HH.MM DD.MM.YYYY
	char c[20];
	uint16_t yr;
	uint8_t century;
	uint8_t subyear;
	struct mtm t;
	timer_get_time(&t);
	yr = TIME_EPOCH_YEAR + t.year;
	century = yr / 100;
	subyear = yr % 100;

	twodigits(c+0, t.hour);
	c[2] = '.';
	twodigits(c+3, t.min);
	c[5] = ' ';
	twodigits(c+6, t.day);
	c[8] = '.';
	twodigits(c+9, t.month);
	c[11] = '.';
	twodigits(c+12, century);
	twodigits(c+14, subyear);
	c[16] = 0;

	ui_scroll_str(c);
}

void ui_run(void) {
	if (timer_get_1hzp()) {
		update_wkday();
	}
	uint8_t b = buttons_get();
	if ((b==BUTTON_S1)||(b==BUTTON_S2)) {
		dsp16seg_settext("");
		for (uint8_t d=0;d<20;d++) {
			if (!buttons_get()) break;
			timer_delay_ms(50);
			mini_mainloop();
		}
		date_scroller();
		timer_delay_ms(200);
		dsp16_settext("");
		timer_delay_ms(200);
		update_wkday();
	}
}
