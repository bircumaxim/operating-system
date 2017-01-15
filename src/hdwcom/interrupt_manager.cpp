#include <hdwcom/interrupt_manager.h>

InterruptManager::GateDescriptor InterruptManager::interruptDescriptorTable[256];
InterruptHandler* InterruptManager::handlers[256];
InterruptManager* InterruptManager::activeInterruptManager = 0;

void InterruptManager::setInterruptDescriptorTableEntry(
	    uint8_t interruptNumber,
	    uint16_t codeSegmentSelectorOffset,
	    void (*handler)(),
	    uint8_t descriptorPrivilegeLevel,
	    uint8_t descriptorType){
    
	interruptDescriptorTable[interruptNumber].handleAddressLowBits = ((uint32_t)handler) & 0xFFFF;
	interruptDescriptorTable[interruptNumber].handleAddressHighBits = (((uint32_t)handler) >> 16) & 0xFFFF;
	interruptDescriptorTable[interruptNumber].gdt_codeSegmentSelector = codeSegmentSelectorOffset;
	
	const uint8_t IDT_DESC_PRESENT = 0x80;
	interruptDescriptorTable[interruptNumber].access = IDT_DESC_PRESENT | ((descriptorPrivilegeLevel & 3) << 5) | descriptorType;
	interruptDescriptorTable[interruptNumber].reserved = 0;
}

InterruptManager::InterruptManager(GlobalDescriptorTable* gdt) : 
    picMasterCommand(0x20),
    picMasterData(0x21),
    picSlaveCommand(0xA0),
    picSlaveData(0xA1){
	
    uint16_t codeSegment = gdt->getCodeSegment();
    const uint8_t IDT_INTERRUPT_GATE = 0xE;
    
    for(uint16_t i = 0; i < 256; i++){
	handlers[i] = 0;
	setInterruptDescriptorTableEntry(i, codeSegment, &ignoreInterruptRequest, 0, IDT_INTERRUPT_GATE);
    }
    
    setInterruptDescriptorTableEntry(0x20, codeSegment, &handleInterruptRequest0x00, 0, IDT_INTERRUPT_GATE);
    setInterruptDescriptorTableEntry(0x21, codeSegment, &handleInterruptRequest0x01, 0, IDT_INTERRUPT_GATE);
    setInterruptDescriptorTableEntry(0x2C, codeSegment, &handleInterruptRequest0x0C, 0, IDT_INTERRUPT_GATE);
    
    picMasterCommand.write(0x11);
    picSlaveCommand.write(0x11);
    
    picMasterData.write(0x20);
    picSlaveData.write(0x28);
    
    picMasterData.write(0x04);
    picSlaveData.write(0x02);
    
    picMasterData.write(0x01);
    picSlaveData.write(0x01);
    
    picMasterData.write(0x00);
    picSlaveData.write(0x00);
    
    InterruptDescriptorTablePointer idt;
    
    idt.size = 256 * sizeof(GateDescriptor) - 1;
    idt.base = (uint32_t)interruptDescriptorTable;
    
    asm volatile("lidt %0" : : "m" (idt));
}

InterruptManager::~InterruptManager(){ }

void InterruptManager::activate(){
    if(activeInterruptManager != 0){
	activeInterruptManager->deactivate();
    }
    activeInterruptManager = this;
    asm("sti");
}

void InterruptManager::deactivate(){
    if(activeInterruptManager == this){
	activeInterruptManager = 0;
	asm("cli");
    }
}

uint32_t InterruptManager::handleInterrupt(uint8_t interruptNumber, uint32_t esp){
    if(activeInterruptManager != 0){
	return activeInterruptManager->doHandleInterrupt(interruptNumber, esp);
    }
    return esp;
}


uint32_t InterruptManager::doHandleInterrupt(uint8_t interruptNumber, uint32_t esp){
    if(handlers[interruptNumber] != 0){
 	esp = handlers[interruptNumber]->handleInterrupt(esp);
    } else if(interruptNumber != 0x20){
	printf("UNHANDLED INTERRUPT ");
	printfHex8(interruptNumber);
	printf("\n");
    }

    if(0x20 <= interruptNumber && interruptNumber < 0x30){
 	picMasterCommand.write(0x20);
 	if(0x20 <= interruptNumber)
 	    picSlaveCommand.write(0x20);
    }
    
    
    return esp;
}

