#ifndef __OPERATING_SYSTEM__CURSOR_H
#define __OPERATING_SYSTEM__CURSOR_H

#include <std/types.h>
#include <std/video_memory.h>

class Cursor{
    private:
	static uint8_t posX;
	static uint8_t posY;
	void renderCursor(uint8_t x, uint8_t y);
	
    public:
	Cursor();
	void setCursor(uint8_t x, uint8_t y);
	void setCursorX(uint8_t x);
	void setCursorY(uint8_t y);
	uint8_t getCursorX();
	uint8_t getCursorY();
	
};

#endif