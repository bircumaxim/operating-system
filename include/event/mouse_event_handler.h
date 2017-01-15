#ifndef __OPERATING_SYSTEM__EVENT__MOUSE_EVENT_HANDLER_H
#define __OPERATING_SYSTEM__EVENT__MOUSE_EVENT_HANDLER_H

#include <std/types.h>

class MouseEventHandler {
    protected:	
	static MouseEventHandler* mouseEventHandlers[256];
	static int mouseEventHandlersCount;

	virtual void onMouseMove(int8_t x, int8_t y);
	virtual void onMouseButtonUp(uint8_t button);
	virtual void onMouseButtonDown(uint8_t button);
	
	void triggerMouseMoveEvent(int8_t x, int8_t y);
	void triggerMouseButtonUpEvent(uint8_t data);
	void triggerMouseButtonDownEvent(uint8_t data);
	
	MouseEventHandler();
	MouseEventHandler(MouseEventHandler* mouseEventHandler);
};

#endif