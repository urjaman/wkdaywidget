##
## Copyright (C) 2018 Urja Rannikko <urjaman@gmail.com>
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##

PROJECT=wkdaysw
DEPS=uart.h main.h i2c.h rtc.h buttons.h time.h timer.h dsp16seg.h Makefile
CC=avr-gcc
LD=avr-ld
OBJCOPY=avr-objcopy
MMCU=atmega328p
#AVRBINDIR=~/avr-tools/bin/
SERIAL_DEV ?= /dev/ttyUSB0
AVRDUDECMD=avrdude -p m328p -c arduino -P $(SERIAL_DEV) -b 115200
CFLAGS=-mmcu=$(MMCU) -Os -fno-inline-small-functions -g -Wno-main -Wall -W -pipe -flto -flto-partition=none -fwhole-program
CMD_SOURCES=commands.c ciface/command_echo.c
SOURCES=main.c uart.c i2c.c rtc.c buttons.c timer.c time.c dsp16seg.c  $(CMD_SOURCES)

all: $(PROJECT).out
	$(AVRBINDIR)avr-size $(PROJECT).out

include ciface/Makefile.ciface

$(PROJECT).hex: $(PROJECT).out
	$(AVRBINDIR)$(OBJCOPY) -j .text -j .data -O ihex $(PROJECT).out $(PROJECT).hex

$(PROJECT).bin: $(PROJECT).out
	$(AVRBINDIR)$(OBJCOPY) -j .text -j .data -O binary $(PROJECT).out $(PROJECT).bin

$(PROJECT).out: $(SOURCES) $(DEPS) timer-ll.o
	$(AVRBINDIR)$(CC) $(CFLAGS) -I./ -o $(PROJECT).out $(SOURCES) timer-ll.o


timer-ll.o: timer-ll.c timer.c main.h
	$(AVRBINDIR)$(CC) $(CFLAGS) -I./ -c -o timer-ll.o timer-ll.c


program: $(PROJECT).hex
	$(AVRBINDIR)$(AVRDUDECMD) -U flash:w:$(PROJECT).hex

objdump: $(PROJECT).out
	$(AVRBINDIR)avr-objdump -xdC $(PROJECT).out | less

clean:
	rm -f $(PROJECT).out
	rm -f $(PROJECT).hex
	rm -f $(PROJECT).s

astyle:
	astyle -A8 -t8 -xC110 -z2 -o -O $(SOURCES) $(HEADERS)

