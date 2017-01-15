#ifndef __OPERATING_SYSTEM__STD__PRINTF_H
#define __OPERATING_SYSTEM__STD__PRINTF_H

#include <std/types.h>
#include <std/video_memory.h>

static uint8_t cursorX = 0;
static uint8_t cursorY = 0;

void printf(char* str);
void printfHex8(uint8_t key);
void printfHex16(uint8_t key);
void printfHex32(uint8_t key);
void clear();

#endif