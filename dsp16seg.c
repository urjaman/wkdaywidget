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
#include "dsp16seg.h"

#define DISP_CHRS DSP16SEG_DISP_CHARS

#define S_F  0x0001
#define S_H  0x0002
#define S_J  0x0004
#define S_K  0x0008
#define S_C  0x0010
#define S_L  0x0020
#define S_M  0x0040
#define S_N  0x0080

#define S_A1 0x0100
#define S_A2 0x0200
#define S_D1 0x0400
#define S_D2 0x0800
#define S_G2 0x1000
#define S_G1 0x2000
#define S_B  0x4000
#define S_E  0x8000

#define S_DP1 _BV(COM0A1)
#define S_DP2 _BV(COM0B1)

/* Only the range from 0x20 to 0x5F, that is
 * some symbols, numbers, and big letters */
static const uint16_t asc2segtab[64] PROGMEM = {
	// Some of the symbol space...
	0,		// 0x20 ' '
	S_J | S_D1,	// !
	S_F | S_B,	// "
	0,		// #

	S_J | S_M | S_A1 | S_A2 | S_F | S_G1 | S_G2 | S_C | S_D2 | S_D1, // $
	S_N | S_K | S_A1 | S_D2, // %
	S_L | S_H | S_A1 | S_J | S_N | S_D1 | S_D2 | S_C, // &
	S_B,		// '

	S_K | S_L, // (
	S_H | S_N, // )
	S_H | S_J | S_K | S_G1 | S_G2 | S_N | S_M | S_L, // *
	S_J | S_M | S_G1 | S_G2, // +

	S_N,			// ','
	S_G1 | S_G2,	// '-'
	0,			// '.' (implemented using the DP leds seperately)
	S_N | S_K,		// '/'

	// Numbers
	S_A1 | S_A2 | S_B | S_C | S_D2 | S_D1 | S_E | S_F, // 0
	S_B | S_C, // 1 (in 7-seg style)
	S_A1 | S_A2 | S_B | S_G2 | S_G1 | S_E | S_D1 | S_D2, // 2
	S_A1 | S_A2 | S_B | S_G2 | S_G1 | S_C | S_D1 | S_D2, // 3
	S_F | S_G1 | S_G2 | S_B | S_C, // 4
	S_A1 | S_A2 | S_F | S_G1 | S_G2 | S_C | S_D2 | S_D1, // 5
	S_A1 | S_A2 | S_F | S_E | S_D1 | S_D2 | S_C | S_G1 | S_G2, // 6
	S_A1 | S_A2 | S_B | S_C, // 7
	S_F | S_B | S_E | S_C | S_A1 | S_A2 | S_G1 | S_G2 | S_D1 | S_D2, // 8
	S_A1 | S_A2 | S_F | S_B | S_G1 | S_G2 | S_C | S_D1 | S_D2, // 9

	// Uhh...

	S_G1 | S_D1, // :
	S_A1 | S_N, // ;
	S_K | S_G2 | S_L, // <
	S_G1 | S_G2 | S_D1 | S_D2, // =
	S_H | S_G1 | S_N, // >
	S_A1 | S_A2 | S_B | S_G2 | S_M, // ?

	S_G2 | S_B | S_A2 | S_A1 | S_F | S_E | S_D1 | S_D2, // @

	// Letters
	S_F | S_A1 | S_A2 | S_B | S_G1 | S_G2 | S_E | S_C, // A
	S_A1 | S_A2 | S_B | S_C | S_D2 | S_D1 | S_J | S_M | S_G1 | S_G2, // B
	S_A1 | S_A2 | S_F | S_E | S_D1 | S_D2,		   // C
	S_A1 | S_A2 | S_B | S_C | S_D2 | S_D1 | S_J | S_M, // D
	S_A1 | S_A2 | S_F | S_G1 | S_G2 | S_E | S_D1 | S_D2, // E
	S_A1 | S_A2 | S_F | S_G1 | S_G2 | S_E, // F
	S_G2 | S_C | S_D2 | S_D1 | S_E | S_F | S_A1 | S_A2, // G
	S_F | S_B | S_G1 | S_G2 | S_E | S_C, // H
	S_J | S_M, // I
	S_J | S_M | S_D1, // J
	S_F | S_E | S_G1 | S_K | S_L, // K
	S_F | S_E | S_D1 | S_D2, // L
	S_E | S_F | S_H | S_K | S_B | S_C, // M
	S_E | S_F | S_H | S_L | S_C | S_B, // N
	S_A1 | S_A2 | S_B | S_C | S_D2 | S_D1 | S_E | S_F, // O
	S_A1 | S_A2 | S_F | S_B | S_G1 | S_G2 | S_E, // P
	S_A1 | S_A2 | S_B | S_C | S_D2 | S_D1 | S_E | S_F | S_L, // Q
	S_A1 | S_A2 | S_F | S_B | S_G1 | S_G2 | S_E | S_L, // R
	S_A1 | S_A2 | S_F | S_G1 | S_G2 | S_C | S_D2 | S_D1, // S
	S_A1 | S_A2 | S_J | S_M, // T
	S_F | S_B | S_E | S_C | S_D1 | S_D2, // U
	S_F | S_E | S_N | S_K, // V
	S_F | S_B | S_E | S_C | S_N | S_L, // W
	S_H | S_K | S_N | S_L,
	S_H | S_K | S_M, // Y
	S_A1 | S_A2 | S_K | S_N | S_D1 | S_D2, // Z

	// A few extra symbols
	S_A2 | S_J | S_M | S_D2, // [
	S_H | S_L, // '\'
	S_A1 | S_J | S_M | S_D1, // ]
	S_N | S_L, // ^
	S_D1 | S_D2 // _
};


/* Legend for help with the segments:
  x-A1-x-A2-x
  |\   |   /|
  F H  J  K B
  |  \ | /  |
  x-G1-x-G2-x
  |  / | \  |
  E N  M  L C
  |/   |   \|
  x-D1-x-D2-x
*/


static void spi_shove(uint8_t data) {
	uint8_t st;
	do {
		SPDR = data;
		st = SPSR;
	} while(st & _BV(WCOL));
}

static void spi_done(void) {
	uint8_t st;
	volatile uint8_t dummy=dummy;
	do {
		st = SPSR;
		dummy = SPDR;
	} while (!(st & _BV(SPIF)));
	_delay_us(2);
}

static void dsp16seg_update(uint16_t *segdat, uint8_t dp) {
	do {
		uint8_t r = TCCR0A & ~(S_DP1 | S_DP2);
		r |= dp;
		TCCR0A = r;
		if (!(dp & S_DP1)) {
			PORTD &= ~_BV(6);
		}
		if (!(dp & S_DP2)) {
			PORTD &= ~_BV(5);
		}
	} while(0);
	PORTB &= ~_BV(2);
	for (int8_t n=DISP_CHRS-1;n>=0;n--) {
		spi_shove(segdat[n] >> 8);
		spi_shove(segdat[n] & 0xFF);
	}
	spi_done();
	PORTB |= _BV(2);
}

void dsp16seg_set_brightness(uint8_t br) {
	/* Main display brightness is PB1/OC1A and inverted */
	/* Decimal points are DP1 = OCOA/PD6 and DP2 = OCOB/PD5 */
	OCR0A = br;
	OCR0B = br;
	OCR1A = br;
}


void dsp16seg_init(void) {
	uint16_t clr[DISP_CHRS] = { 0 };

	/* Set correct default states on the SPI/PORTB */
	PORTB = _BV(2) | _BV(1);
	/* CLK, MOSI, CS (latch clock), ~DISP_ON */
	DDRB = _BV(5) | _BV(3) | _BV(2) | _BV(1);

	/* Enable drive on the decimal point lines */
	DDRD |= _BV(5);
	DDRD |= _BV(6);

	/* Enable the SPI peripheral */
	SPCR = _BV(SPE) | _BV(MSTR);
	SPSR = _BV(SPI2X);

	/* DP PWM to Fast PWM mode */
	TCCR0A |= _BV(WGM01) | _BV(WGM00);

	/* SPI and DP PWM is ready, clear the display to avoid glitches */
	dsp16seg_update(clr, 0);

	/* Timer 1 into similar 8-bit PWM mode as Timer 0 (except a bit slower because geeze) */
	TCCR1A = _BV(COM1A1) | _BV(COM1A0) | _BV(WGM10);
	TCCR1B = _BV(WGM12) | _BV(CS11);

	/* Set a sensible brightness */
	dsp16seg_set_brightness(8);
}


uint8_t dsp16seg_settext(const char *txt) {
	uint16_t segdat[DISP_CHRS] = { 0 };
	uint8_t dp = 0;
	uint8_t sn = 0;
	uint8_t tn = 0;
	for (;txt[tn];tn++) {
		uint8_t c = toupper(txt[tn]);
		if ((c < 0x20) || (c >= 0x60)) c = ' ';
		if (c == '.') {
			if (!sn) sn++;
			if ((sn == 1)&&(dp & S_DP1)) sn++;
			if ((sn == 2)&&(dp & S_DP2)) break;
			if (sn == 1) dp |= S_DP1;
			else dp |= S_DP2;
			continue;
		}
		if (sn == 2) break;
		segdat[sn++] = pgm_read_word(&(asc2segtab[c - 0x20]));
	}
	dsp16seg_update(segdat, dp);
	return tn;
}
