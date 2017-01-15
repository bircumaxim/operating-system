#include <terminal.h>

Terminal::Terminal():KeyEventHandler(this), MouseEventHandler(this){
    
}

void Terminal::onKeyPress(char* data){
    printf(data);
}

void Terminal::onKeyRelease(char* data){
    
}

void Terminal::onMouseMove(int8_t x, int8_t y){
    //TODO handle here mouse movment events.
}

void Terminal::onMouseButtonDown(uint8_t button){
    if(button == 0x01){
	printf("Left Click\n");
    } else if (button == 0x02){
	printf("Right Click\n");
    } else if (button == 0x03){
	printf("Middle Click\n");
    }
}