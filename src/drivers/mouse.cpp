#include <drivers/mouse.h>

void printf(char*);
void printfHex(uint8_t );

MouseDriver::MouseDriver(InterruptManager* interruptManager): 
    InterruptHandler(0x2C, interruptManager),
    MouseEventHandler(),
    dataPort(0x60), 
    commandPort(0x64){
    
    offset = 0;
    lastButtonState = 0;
    
    invertBitColor(80*12+40);
}

MouseDriver::~MouseDriver(){}

void MouseDriver::activate(){    
    commandPort.write(0xA8); // activate interrupts
    commandPort.write(0x20); // command 0x20 = read controller command byte
    uint8_t status = dataPort.read() | 2;
    commandPort.write(0x60); // command 0x60 = set controller command byte
    dataPort.write(status);
    
    commandPort.write(0xD4);
    dataPort.write(0xF4);
    dataPort.read();
}

uint32_t MouseDriver::handleInterrupt(uint32_t esp){
    uint32_t status = commandPort.read();
    
    if(!(status & 0x20))
	return esp;
    
    static int8_t posX = 40; //Center
    static int8_t posY = 12; //center
    
    buffer[offset] = dataPort.read();
    offset = (offset + 1) % 3;
    
    if(offset == 0){
	invertBitColor(80 * posY + posX);

	posX += buffer[1];
	if(posX < 0) posX = 0;
	if(posX >= 80) posX = 79;
	
	posY -= buffer[2];
	if(posY < 0) posY = 0;
	if(posY >= 25) posY = 24;
	
	invertBitColor(80 * posY + posX);
	
	for(uint8_t i = 0; i < 3; i++){
	    if((buffer[0] & (0x01 << i)) != (lastButtonState & 0x01 << i)){
		if(lastButtonState & (0x01 << i)){
		    MouseEventHandler::triggerMouseButtonUpEvent(i+1);
		} else {
		    MouseEventHandler::triggerMouseButtonDownEvent(i+1);
		}
	    }
	}
	MouseEventHandler::triggerMouseMoveEvent(posX,posY);
	
	lastButtonState = buffer[0];
	
    }
    
    return esp;
}
