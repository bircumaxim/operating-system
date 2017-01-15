#ifndef __OPERATING_SYSTEM__DRIVERS__MOUSE_H
#define __OPERATING_SYSTEM__DRIVERS__MOUSE_H

#include <std/types.h>
#include <hdwcom/interrupt_manager.h>
#include <hdwcom/port/port.h>
#include <drivers/driver.h>
#include <event/mouse_event_handler.h>

class MouseDriver : public InterruptHandler, public Driver, public MouseEventHandler {
    private:
	Port8Bit dataPort;
	Port8Bit commandPort;
	
	uint8_t buffer[3];
	uint8_t offset;
	uint8_t lastButtonState;
	
    public:
	MouseDriver(InterruptManager* interruptManager);
	~MouseDriver();
	virtual uint32_t handleInterrupt(uint32_t esp);
	virtual void activate();
};

#endif