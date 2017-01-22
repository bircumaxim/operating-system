#ifndef __OPERATING_SYSTEM__DIRVERS__KEYBOARD_H
#define __OPERATING_SYSTEM__DRIVERS__KEYBOARD_H

#include <std/types.h>
#include <std/printf.h>
#include <hdwcom/interrupt_manager.h>
#include <hdwcom/port/port.h>
#include <drivers/driver.h>
#include <event/key_event_handler.h>

class KeyboardDriver : public InterruptHandler, public Driver , KeyEventHandler{
    private:
	Port8Bit dataPort;
	Port8Bit commandPort;
	
	bool shift;
	
	char* getChar(uint8_t);
	char getLetter(uint8_t);
	char getSignOrNumber(uint8_t);
	
    public:
	KeyboardDriver(InterruptManager* interruptManager);
	~KeyboardDriver();
	virtual uint32_t handleInterrupt(uint32_t esp);
	virtual void activate();
};

#endif