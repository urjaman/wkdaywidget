#pragma once

#define DSP16SEG_DISP_CHARS 2

void    dsp16seg_init(void);
void    dsp16seg_set_brightness(uint8_t br);
uint8_t dsp16seg_settext(const char *txt);
