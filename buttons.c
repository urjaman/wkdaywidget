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
#include "buttons.h"
#include "uart.h"

void buttons_init(void) {
	PORTC |= _BV(2);
	PORTC |= _BV(3); // enable pull-ups
}

uint8_t buttons_get_v(void) {
	uint8_t rv = (uint8_t)~PINC;
	rv = (uint8_t)rv & (uint8_t)(_BV(2)|_BV(3));
	rv = (uint8_t)rv >> (uint8_t)2;
	return rv;
}

uint8_t buttons_get(void) {
	uint8_t v = buttons_get_v();
	if (!v) return 0;
	timer_delay_ms(125);
	for(;;) {
		uint8_t sv;
		timer_delay_ms(30);
		sv = buttons_get_v();
		if (sv == v) {
			return v;
		}
		v = sv;
	}
}
