#ifndef __OPERATING_SYSTEM__STD__PRINTF_H
#define __OPERATING_SYSTEM__STD__PRINTF_H

#include <std/types.h>
#include <std/video_memory.h>
#include <cursor.h>

static Cursor cursor;

void printf(char* str);
void printfHex8(uint8_t key);
void printfHex16(uint8_t key);
void printfHex32(int32_t key);
void clear();

bool strcmp(char* str1, char* str2);
int32_t atoi(char *str);
char* itoa(int num, char* str, int base);
bool isNumber(char character);
void reverse(char str[], int length);
#endif