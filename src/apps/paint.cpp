#include <apps/paint.h>
#include <std/printf.h>

Paint::Paint(VideoGraphicsArray* vga) : App("paint"), MouseEventHandler(this){
    this->vga = vga;
}

void Paint::run(){
    printf("Welcome to paint.\n");
    vga->setMode(320,200,8);
    vga->fillRectangle(0,0,320,200,0xFF,0xFF,0xFF);
}

void Paint::onMouseButtonDown(uint8_t button){
   if(!isRunning)
	return;
    if(button == 0x01){
	cursor.setCursor(mousePosX, mousePosY);
    }
}

void Paint::onMouseMove(int8_t x, int8_t y){
    if(!isRunning)
	return;
    mousePosX = x;
    mousePosY = y;
}

char* Paint::getDescription(){
    return "description";
}