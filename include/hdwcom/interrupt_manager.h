#ifndef __OS__HDWCOM__INTERRUPTS_H
#define __OS__HDWCOM__INTERRUPTS_H

#include <std/types.h>
#include <std/printf.h>
#include <hdwcom/interrupt_handler.h>
#include <hdwcom/port/slow_port_8.h>
#include <gdt/gdt.h>

class InterruptHandler;

class InterruptManager{
friend class InterruptHandler;    
    protected:
	static InterruptManager* activeInterruptManager;
 	static InterruptHandler* handlers[256];
	
	struct GateDescriptor{
	    uint16_t handleAddressLowBits;
	    uint16_t gdt_codeSegmentSelector;
	    uint8_t reserved;
	    uint8_t access;
	    uint16_t handleAddressHighBits;
	} __attribute__((packed));
	
	static GateDescriptor interruptDescriptorTable[256];
	
	struct InterruptDescriptorTablePointer{
	    uint16_t size;
	    uint32_t base;
	} __attribute__((packed));
	
	static void setInterruptDescriptorTableEntry(
	    uint8_t interruptNumber,
	    uint16_t codeSegmentSelectorOffset,
	    void (*handler)(),
	    uint8_t DescriptorPrivilegeLevel,
	    uint8_t DescriptorType
	);
	
	Port8BitSlow picMasterCommand;
	Port8BitSlow picMasterData;
	Port8BitSlow picSlaveCommand;
	Port8BitSlow picSlaveData;
	
    public:
	InterruptManager(GlobalDescriptorTable* gdt);
	~InterruptManager();
	
	void activate();
	void deactivate();
	
	static uint32_t handleInterrupt(uint8_t interruptNumber, uint32_t esp);
	uint32_t doHandleInterrupt(uint8_t interruptNumber, uint32_t esp);
	
	static void ignoreInterruptRequest();  //Time out interrupt
	static void handleInterruptRequest0x00();  //Time out interrupt
	static void handleInterruptRequest0x01();  //KeyBoard interrupt
	static void handleInterruptRequest0x0C();  //Mouse interrupt
};
    
#endif