/*
 * Copyright (C) 2020 Urja Rannikko <urjaman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "main.h"
#include "timer.h"
#include "dsp16seg.h"
#include "buttons.h"
#include "ui.h"
#include "rtc.h"
#include <util/crc16.h>

/* Language select - uncomment the one you want to use. */

#include "lang_fi.h"
//#include "lang_en.h"

const char wkdaystr[] PROGMEM = WEEKDAYSTR;

const uint8_t bright_table[10] PROGMEM = {
//	0  1  2  3  4   5  6   7     8    9
	0, 1, 2, 4, 8, 16, 32, 64, 128, 255
};

#define SAVE_MAGIC 0x69
static struct rtc_savestate {
	uint8_t magic;
	uint8_t br_day;
	uint8_t br_night;
	uint8_t rsvd[7]; // in case we need more settings in the future
	uint8_t crc;
} ss;

uint8_t crc8(void *b_, uint8_t cnt) {
	uint8_t *b = b_;
	uint8_t crc = 0;
	for (uint8_t i = 0; i < cnt; i++) {
		crc = _crc_ibutton_update(crc, b[i]);
	}
	return crc;
}

static void load_ss(void) {
	struct rtc_savestate tr;
#if 0
	if (rtc_read_ram(&tr, sizeof(struct rtc_savestate)) != 0)
		goto err;
	if (tr.magic != SAVE_MAGIC)
		goto err;
	if (crc8(&tr, sizeof(struct rtc_savestate) - 1) != tr.crc)
		goto err;
	if (tr.br_day >= 10)
		goto err;
	if (tr.br_night >= 10)
		goto err;
	ss = tr;
	return;
err:
#endif
	ss.br_day = 6;
	ss.br_night = 3;
	return;
}

static void save_ss(void) {
	ss.magic = SAVE_MAGIC;
	ss.crc = crc8(&ss, sizeof(struct rtc_savestate) - 1);
	//rtc_write_ram(&ss, sizeof(struct rtc_savestate));
}

static void update_brightness(void) {
	uint8_t stat = 0; // 0 = night, 1=transition to day, 2=day, 3=transition to night
	struct mtm t;
	timer_get_time(&t);
	if ((t.hour == 9)&&(t.min == 0)) {
		stat = 1;
	} else if ((t.hour == 21)&&(t.min == 0)) {
		stat = 3;
	} else if ((t.hour >= 9)&&(t.hour < 21)) {
		stat = 2;
	}
	uint8_t daybr = pgm_read_byte(bright_table + ss.br_day);
	uint8_t nightbr = pgm_read_byte(bright_table + ss.br_night);
	uint16_t diff;
	uint8_t br;
	switch (stat) {
		case 0:
			br = nightbr;
			break;
		case 1:
			diff = daybr - nightbr;
			diff *= t.sec;
			diff /= 60;
			br = nightbr + diff;
			break;

		case 2:
			br = daybr;
			break;

		case 3:
			diff = daybr - nightbr;
			diff *= t.sec;
			diff /= 60;
			br = daybr - diff;
			break;
	}
	dsp16seg_set_brightness(br);
}

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

void ui_scroll_str(const char* str, uint8_t s) {
	char lstr[5];
	uint8_t ml = strlen(str);
	uint8_t off = 0;
	uint8_t dl = 0;
	do {
		uint8_t cl = ml-off < 4 ? ml-off : 4;
		memcpy(lstr, str+off, cl);
		lstr[cl] = 0;
		dl = dsp16seg_settext(lstr);
		for (uint8_t d=0;d<s;d++) {
			timer_delay_ms(50);
			timer_set_waiting();
			mini_mainloop();
			if (buttons_get_v()) return;
		}
		off++;
		if (lstr[1] == '.') off++;
	} while (((off-1)+dl) < ml);
}

static char uiscroll_buf[48];
static void ui_scroll_str_P(const PGM_P str, uint8_t s) {
	strcpy_P(uiscroll_buf, str);
	ui_scroll_str(uiscroll_buf, s);
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

	ui_scroll_str(c, 5);
}

uint8_t numeric_entry(uint8_t start, uint8_t min, uint8_t max, uint8_t toval, void (*cb)(uint8_t)) {
	const int timeout = 75;
	uint32_t touchtime = timer_get();
	uint8_t n = start;
	char e[3];
	e[2] = 0;
	if (cb) cb(n);
	do {
		twodigits(e, n);
		dsp16seg_settext(e);
		timer_delay_ms(100);
		mini_mainloop();

		uint8_t b = buttons_get();
		switch (b) {
			case 0: {
					int passed = timer_get() - touchtime;
					if (passed >= timeout) {
						return toval;
					}
				}
				break;
			case BUTTON_S1:
				touchtime = timer_get();
				if (n==max) n=min;
				else n++;
				if (cb) cb(n);
				break;
			case BUTTON_S2:
				touchtime = timer_get();
				if (n==min) n=max;
				else n--;
				if (cb) cb(n);
				break;
			case BUTTON_BOTH:
				return n;
		}
	} while(1);
}

void wait_nokey(void) {
	char st[3];
	strcpy_P(st, PSTR("__"));
	dsp16seg_settext(st);
	for (uint8_t d=0;d<100;d++) {
		if (!buttons_get()) break;
		timer_delay_ms(50);
		mini_mainloop();
	}
}

uint8_t text_select(uint8_t start, uint8_t toval, uint8_t count, const PGM_P *table) {
	const int timeout = 45;
	uint32_t touchtime = timer_get();
	uint8_t n = start;
	uint8_t scroll_skipcnt = 0;
	wait_nokey();
	do {
		if (!scroll_skipcnt) {
			dsp16seg_settext("");
			timer_delay_ms(200);
			ui_scroll_str_P(table[n], 3);
		}
		timer_delay_ms(50);
		mini_mainloop();
		scroll_skipcnt++;
		if (scroll_skipcnt == 10) scroll_skipcnt = 0;

		uint8_t old_n = n;
		uint8_t b = buttons_get();
		switch (b) {
			case 0: {
					int passed = timer_get() - touchtime;
					if (passed >= timeout) {
						return toval;
					}
				}
				break;
			case BUTTON_S1:
				if (n == count-1) n=0;
				else n++;
				break;
			case BUTTON_S2:
				if (!n) n = count-1;
				else n--;
				break;
			case BUTTON_BOTH:
				return n;
		}
		if (old_n != n) {
			touchtime = timer_get();
			scroll_skipcnt = 0;
			wait_nokey();
		}
	} while(1);
}


void set_timedate(void) {
	uint16_t yr;
	uint8_t century;
	uint8_t subyear;
	struct mtm t;
	timer_get_time(&t);
	yr = TIME_EPOCH_YEAR + t.year;
	century = yr / 100;
	subyear = yr % 100;

	const uint8_t abort_val = 255;

	wait_nokey();
	ui_scroll_str_P(PSTR(CENTURY_STR),4);
	century = numeric_entry(century, 20, 22, abort_val, NULL);
	if (century == abort_val) return;

	wait_nokey();
	ui_scroll_str_P(PSTR(YEAR_STR), 4);
	subyear = numeric_entry(subyear, 00, century==22 ? 55 : 99, abort_val, NULL);
	if (subyear == abort_val) return;

	yr = century * 100 + subyear;
	t.year = yr - TIME_EPOCH_YEAR;

	wait_nokey();
	ui_scroll_str_P(PSTR(MONTH_STR), 4);
	t.month = numeric_entry(t.month, 1, 12, abort_val, NULL);
	if (t.month == abort_val) return;

	wait_nokey();
	ui_scroll_str_P(PSTR(DAY_STR), 4);
	t.day = numeric_entry(t.day, 1, month_days(t.year,t.month-1), abort_val, NULL);
	if (t.day == abort_val) return;

	wait_nokey();
	ui_scroll_str_P(PSTR(HOURS_STR), 4);
	t.hour = numeric_entry(t.hour, 0, 23, abort_val, NULL);
	if (t.hour == abort_val) return;

	wait_nokey();
	ui_scroll_str_P(PSTR(MINUTES_STR), 4);
	t.min = numeric_entry(t.min, 0, 59, abort_val, NULL);
	if (t.min == abort_val) return;

	/* Umm yeah set time time on the minute change, so zero the seconds. */
	t.sec = 0;

	timer_set_time(&t);

	wait_nokey();
	ui_scroll_str_P(PSTR(TIME_SET_DONE_STR),3);
}


void brightness_preview_cb(uint8_t brv) {
	uint8_t hwbr = pgm_read_byte(bright_table + (brv-1));
	dsp16seg_set_brightness(hwbr);
}

void main_menu(void) {
	const PGM_P table[] = {
		PSTR(TIME_SET_STR),
		PSTR(NIGHT_BR_SET_STR),
		PSTR(DAY_BR_SET_STR),
		PSTR(EXIT_STR)
	};
	uint8_t sel = text_select(0, 3, 4, table);
	switch (sel) {
		default:
			return;
		case 0:
			set_timedate();
			return;

		case 1:
		case 2: {
				uint8_t brv = (sel == 2 ? ss.br_day : ss.br_night) + 1;
				uint8_t max = sel == 2 ? 10 : ss.br_day+1;
				uint8_t min = sel == 2 ? ss.br_night+1 : 1;
				wait_nokey();
				brv = numeric_entry(brv, min, max, brv, brightness_preview_cb);
				if (sel == 2) {
					ss.br_day = brv-1;
				} else {
					ss.br_night = brv-1;
				}
				update_brightness();
				save_ss();
			}
			break;
	}
}

void ui_init(void) {
	load_ss();
}

void ui_run(void) {
	if (timer_get_1hzp()) {
		update_brightness();
		update_wkday();
	}
	uint8_t b = buttons_get();
	if ((b==BUTTON_S1)||(b==BUTTON_S2)) {
		wait_nokey();
		date_scroller();
		timer_delay_ms(200);
		dsp16seg_settext("");
		timer_delay_ms(200);
		update_wkday();
	} else if (b==BUTTON_BOTH) {
		main_menu();
		timer_delay_ms(200);
		dsp16seg_settext("");
		timer_delay_ms(200);
		update_wkday();
	}
}
