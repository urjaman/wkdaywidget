#pragma once

uint8_t rtc_read(struct mtm* tm);
void rtc_write(struct mtm* tm);
uint8_t rtc_valid(void);

/* These are for accessing the battery-backed RAM of the RTC for a
 * single saved blob (offset is fixed by the RTC module so it can adapt to different RTCs). */
uint8_t rtc_read_ram(void *buf, uint8_t len);
uint8_t rtc_write_ram(void *buf, uint8_t len);
