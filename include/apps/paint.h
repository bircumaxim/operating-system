#ifndef __OPERATING_SYSTEM__APPS__PAINT_H
#define __OPERATING_SYSTEM__APPS__PAINT_H

#include <event/mouse_event_handler.h>
#include <drivers/vga.h>
#include <apps/app.h>

class Paint : public App , MouseEventHandler{
    private:
	VideoGraphicsArray *vga;
    protected:
	int8_t mousePosX;
	int8_t mousePosY;
	virtual void onMouseButtonDown(uint8_t button);    
	virtual void onMouseMove(int8_t x, int8_t y);
    public:
	virtual void run();
	virtual char* getDescription();
	Paint(VideoGraphicsArray *vga);
};

#endif