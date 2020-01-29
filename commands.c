#include "main.h"
#include "uart.h"
#include "console.h"
#include "lib.h"
#include "ciface.h"
#include "appdb.h"
#include "timer.h"
#include "buttons.h"
#include "dsp16seg.h"

CIFACE_APP(d16s_cmd, "DSP16")
{
	if (token_count==2) {
		dsp16seg_settext((char*)tokenptrs[1]);
		sendstr_P(PSTR("Set."));
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