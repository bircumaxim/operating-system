#ifndef __OPERATING_SYSTEM__EVENT__KEY_EVENT_HANDLER_H
#define __OPERATING_SYSTEM__EVENT__KEY_EVENT_HANDLER_H

class KeyEventHandler {
    protected:	
	static KeyEventHandler* keyEventHandlers[256];
	static int keyEventHandlersCount;

	virtual void onKeyPress(char* data);
	virtual void onKeyRelease(char* data);
	
	void triggerPressEvent(char* data);
	void triggerReleaseEvent(char* data);
	
	KeyEventHandler();
	KeyEventHandler(KeyEventHandler* keyEventHandler);
};

#endif