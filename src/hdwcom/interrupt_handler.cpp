#include <hdwcom/interrupt_handler.h>

InterruptHandler::InterruptHandler(uint8_t interruptNumber, InterruptManager* interruptManger){
    this->interruptNumber = interruptNumber;
    this->interruptManager = interruptManager;
    interruptManager->handlers[interruptNumber] = this;
}

InterruptHandler::~InterruptHandler(){
    if(interruptManager->handlers[interruptNumber] == this)
	interruptManager->handlers[interruptNumber] = 0;
}
 
uint32_t InterruptHandler::handleInterrupt(uint32_t esp){
    return esp;
}