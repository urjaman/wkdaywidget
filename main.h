#pragma once

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void mini_mainloop(void);
void cli_bgloop(void);

/* Enable 24-bit types as an optimization for gcc 4.7+ */
#if (((__GNUC__ == 4)&&(__GNUC_MINOR__ >= 7)) || (__GNUC__ > 4))
typedef __int24 int24_t;
typedef __uint24 uint24_t;
#else
/* provide 32-bit compatibility defines. */
#warning "32-bit compatibility defines being used for 24-bit types"
typedef int32_t int24_t;
typedef uint32_t uint24_t;
#endif

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
