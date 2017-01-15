#include <drivers/keyboard.h>
KeyboardDriver::KeyboardDriver(InterruptManager* interruptManager):
    InterruptHandler(0x21, interruptManager),
    KeyEventHandler(),
    dataPort(0x60),
    commandPort(0x64){
}

KeyboardDriver::~KeyboardDriver(){}

void KeyboardDriver::activate(){
    while(commandPort.read() & 0x1){
	dataPort.read();
    }
    commandPort.write(0xAE); // activate interrupts
    commandPort.write(0x20); // command 0x20 = read controller command byte
    uint8_t status = (dataPort.read() | 1) & ~0x10;
    commandPort.write(0x60); // command 0x60 = set controller command byte
    dataPort.write(status);
    dataPort.write(0xF4);
}

uint32_t KeyboardDriver::handleInterrupt(uint32_t esp){
    uint8_t key = dataPort.read();
   
    
    switch(key){
    	case 0x2A: case 0x36: shift = true; break;
	case 0xAA: case 0xB6: shift = false; break;
    }
    
    if(key < 0x80){
	KeyEventHandler::triggerPressEvent(getChar(key));
    } else {
	KeyEventHandler::triggerReleaseEvent(getChar(key - 0x80));
    }
    return esp;
}

char* KeyboardDriver::getChar(uint8_t key){
    char* character = "";
    if(key >= 0x10 && key <=0x32){
	character[0] = shift ? getLetter(key) & 0x5F : getLetter(key);
	return character;
    } 
    character[0] = getSignOrNumber(key);
    return character;
}

char KeyboardDriver::getLetter(uint8_t key){
    switch(key){
	case 0x10: return 'q';
	case 0x11: return 'w';
	case 0x12: return 'e';
	case 0x13: return 'r';
	case 0x14: return 't';
	case 0x15: return 'y';
	case 0x16: return 'u';
	case 0x17: return 'i';
	case 0x18: return 'o';
	case 0x19: return 'p';
			  
	case 0x1E: return 'a';
	case 0x1F: return 's';
	case 0x20: return 'd';
	case 0x21: return 'f';
	case 0x22: return 'g';
	case 0x23: return 'h';
	case 0x24: return 'j';
	case 0x25: return 'k';
	case 0x26: return 'l';
		          
	case 0x2C: return 'z';
	case 0x2D: return 'x';
	case 0x2E: return 'c';
	case 0x2F: return 'v';
	case 0x30: return 'b';
	case 0x31: return 'n';
	case 0x32: return 'm';
	default: return '\0';
    }
}

char KeyboardDriver::getSignOrNumber(uint8_t key){
    switch(key){
	case 0x02: return shift ? '!' : '1';
	case 0x03: return shift ? '@' : '2';
	case 0x04: return shift ? '#' : '3';
	case 0x05: return shift ? '$' : '4';
	case 0x06: return shift ? '%' : '5';
	case 0x07: return shift ? '^' : '6';
	case 0x08: return shift ? '&' : '7';
	case 0x09: return shift ? '*' : '8';
	case 0x0A: return shift ? '(' : '9';
	case 0x0B: return shift ? ')' : '0';
			  
	
	case 0x33: return shift ? '<' : ',';
	case 0x34: return shift ? '>' : '.';
	case 0x35: return shift ? '/' : '-';
		    
	case 0x1C: return '\n';
	case 0x39: return ' ';
	default: return '\0';
    }
}