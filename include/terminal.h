#ifndef __OPERATING_SYSTEM__TERMINAL_H
#define __OPERATING_SYSTEM__TERMINAL_H

#include <std/printf.h>
#include <std/video_memory.h>
#include <event/key_event_handler.h>
#include <event/mouse_event_handler.h>


class Terminal : public KeyEventHandler, public MouseEventHandler{
    public:
	Terminal();
	~Terminal();
	virtual void onKeyPress(char* data);
	virtual void onKeyRelease(char* data);
	virtual void onMouseMove(int8_t x, int8_t y);
	virtual void onMouseButtonDown(uint8_t button);
};

#endif