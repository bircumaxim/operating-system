#ifndef __OPERATING__SYSTEM__APPS__APP_H
#define __OPERATING__SYSTEM__APPS__APP_H

#include <std/printf.h>

class App {
    protected:
	char* appName;
	App(char* name);
	
    public:
	virtual void run();
	virtual char* getDescription();
	char* getAppName();
	bool isRunning;
};

#endif