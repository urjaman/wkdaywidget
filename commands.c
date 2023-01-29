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
#include "uart.h"
#include "console.h"
#include "lib.h"
#include "ciface.h"
#include "appdb.h"
#include "timer.h"
#include "buttons.h"
#include "dsp16seg.h"
#include "ui.h"
#include "i2c.h"


CIFACE_APP(d16s_cmd, "DSP16")
{
	if (token_count==2) {
		dsp16seg_settext((char*)tokenptrs[1]);
		sendstr_P(PSTR("Set."));
	}

}

CIFACE_APP(d16br_cmd, "BR")
{
	if (token_count==2) {
		dsp16seg_set_brightness(str2uchar(tokenptrs[1]));
		sendstr_P(PSTR("Set."));
	}

}

CIFACE_APP(uiscr_cmd, "SCRL")
{
	if ((token_count >= 2) && (token_count <= 3)) {
		uint8_t spd = 4;
		if (token_count == 3) {
			uint8_t tspd = str2uchar(tokenptrs[2]);
			if ((tspd >= 1) && (tspd <= 10)) spd = tspd;
		}
		sendstr_P(PSTR("Scrolling..."));
		dsp16seg_settext("");
		timer_delay_ms(200);
		ui_scroll_str((char*)tokenptrs[1], spd);
		timer_delay_ms(200);
		dsp16seg_settext("");
		sendstr_P(PSTR(" Scrolled."));
	}

}



CIFACE_APP(btns_cmd, "BTNS")
{
	do {
		uint8_t v = buttons_get();
		PGM_P btn = PSTR("BUTTON_");
		switch (v) {
			default:
				sendstr_P(btn);
				sendstr_P(PSTR("UNKNOWN"));
				break;
			case BUTTON_S1:
				sendstr_P(btn);
				sendstr_P(PSTR("S1"));
				break;
			case BUTTON_S2:
				sendstr_P(btn);
				sendstr_P(PSTR("S2"));
				break;
			case BUTTON_NONE:
				if (token_count == 1) {
					sendstr_P(btn);
					sendstr_P(PSTR("NONE"));
				}
				break;
			case BUTTON_BOTH:
				sendstr_P(btn);
				sendstr_P(PSTR("BOTH"));
				break;
		}
		if (v != BUTTON_NONE) token_count = 1;
		cli_bgloop();
	} while (token_count > 1);
}

CIFACE_APP(timer_cmd, "TIMER")
{
	luint2outdual(timer_get());
}

CIFACE_APP(i2c_scan_cmd, "I2CSCAN")
{
	uint8_t a=2;
	do {
		uint8_t r = i2c_start(a);
		if (r == 0) {
			i2c_stop();
			luint2outdual(a);
		}
		a += 2;
	} while (a);
}
