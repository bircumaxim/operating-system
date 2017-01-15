#ifndef __OS__HDWCOM__INTERRUPT_HANDLER_H
#define __OS__HDWCOM__INTERRUPT_HANDLER_H

#include <hdwcom/interrupt_manager.h>

class InterruptManager;

class InterruptHandler{
    protected:
	uint8_t interruptNumber;
	InterruptManager* interruptManager;
	InterruptHandler(uint8_t interruptNumber, InterruptManager* interruptManger);
	~InterruptHandler();
    public:
	virtual uint32_t handleInterrupt(uint32_t esp);
};

#endif