#pragma once
#include "time.h"
uint8_t rtc_read(struct mtm* tm);
void rtc_write(struct mtm* tm);
uint8_t rtc_valid(void);
uint8_t rtc_init(void);
int16_t rtc_temp(void);
