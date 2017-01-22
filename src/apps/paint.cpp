#include <apps/paint.h>
#include <std/printf.h>

Paint::Paint(VideoGraphicsArray* vga) : App("paint"), MouseEventHandler(this){
    this->vga = vga;
    isHolding= false;
}

void Paint::run(){
    vga->setMode(320, 200, 8);
    vga->fillRectangle(0, 0, 320, 200, 0xFF, 0xFF, 0xFF);
}

void Paint::onMouseButtonDown(uint8_t button){
   if(!isRunning)
	return;
    if(button == 0x01){
	isHolding = true;
    }
}

void Paint::onMouseButtonUp(uint8_t button){
   if(!isRunning)
	return;
    if(button == 0x01){
	isHolding = false;
    }
}

void Paint::onMouseMove(int8_t x, int8_t y){
    if(!isRunning)
	return;
    if(!isHolding){
	vga->fillRectangle(mousePosX, mousePosY, 3, 3, 0xFF, 0xFF, 0xFF);
    }
    mousePosX = x * (320 / 79);
    mousePosY = y * (200 / 24);
    
    vga->fillRectangle(mousePosX, mousePosY, 3, 3, 0x00, 0x00, 0x00);
    
    
    if(isHolding){
	vga->fillRectangle(mousePosX - 3, mousePosY - 3, 10, 10, 0x00, 0x00, 0x00);
    }
}


char* Paint::getDescription(){
    return "     turns on graphical mode";
}