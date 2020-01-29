/*
 * Copyright (C) 2009,2020 Urja Rannikko <urjaman@gmail.com>
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
#include "i2c.h"
#include "uart.h"
#include "ciface.h"
#include "buttons.h"
#include "timer.h"
#include "console.h"

void cli_bgloop(void) {
	timer_run();
	if ((uart_isdata()) ||(getline_i) ) timer_activity();
}

void mini_mainloop(void) {
	cli_bgloop();
	ciface_run();
}

void main (void) __attribute__ ((noreturn));


void main(void) {
	uart_init();
	ciface_init();
	timer_init();
	buttons_init();
	i2c_init();
	for(;;) {
		mini_mainloop();
	}
}


