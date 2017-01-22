#ifndef __OPERATING_SYSTEM__APPS__WRITER_H
#define __OPERATING_SYSTEM__APPS__WRITER_H

#include <event/key_event_handler.h>
#include <event/mouse_event_handler.h>
#include <apps/app.h>

class Writter : public App , KeyEventHandler, MouseEventHandler{
    protected:
	int8_t mousePosX;
	int8_t mousePosY;
    	virtual void onKeyPress(char* data);    
	virtual void onMouseButtonDown(uint8_t button);    
	virtual void onMouseMove(int8_t x, int8_t y);
    public:
	virtual void run();
	virtual char* getDescription();
	Writter();
};

#endif