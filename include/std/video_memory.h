#ifndef __OPERATING_SYSTEM__STD__VIDEO__MEMORY_H
#define __OPERATING_SYSTEM__STD__VIDEO__MEMORY_H

#include <std/types.h>

static uint16_t* VideoMemory = (uint16_t*)0xb8000;
void invertBitColor(int bitIndex);
void setBit(int bitIndex, char data);

#endif