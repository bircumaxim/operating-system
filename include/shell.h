#ifndef __OPERATING_SYSTEM__TERMINAL_H
#define __OPERATING_SYSTEM__TERMINAL_H

#include <std/printf.h>
#include <std/video_memory.h>
#include <event/key_event_handler.h>
#include <apps/app.h>

class Shell : public KeyEventHandler {
    protected:
	App* apps[256];
	int appsCount;
	App* runningApp;
	
	void runCommand(char* command);
	virtual void onKeyPress(char* data);    
    public:	
	void addApp(App *app);
	Shell();
	~Shell();
	
	
};

#endif