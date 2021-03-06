#include <apps/writter.h>
#include <std/printf.h>

Writter::Writter() : App("writter"), KeyEventHandler(this), MouseEventHandler(this){ }

void Writter::run(){
    printf("Welcome to writter.\n");
}

void Writter::onKeyPress(char* data){
    if(!isRunning)
	return;
    printf(data);
}

void Writter::onMouseButtonDown(uint8_t button){
   if(!isRunning)
	return;
    if(button == 0x01){
	cursor.setCursor(mousePosX, mousePosY);
    }
}

void Writter::onMouseMove(int8_t x, int8_t y){
    if(!isRunning)
	return;
    invertBitColor(80 * mousePosY + mousePosX);
    
    mousePosX = x;
    mousePosY = y;
    
    invertBitColor(80 * mousePosY + mousePosX);
}

char* Writter::getDescription(){
    return "   simple text writter";
}