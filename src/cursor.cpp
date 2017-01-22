#include <cursor.h>
#include <std/printf.h>
uint8_t Cursor::posX = 0;
uint8_t Cursor::posY = 0;

Cursor::Cursor(){
}

void Cursor::setCursor(uint8_t x, uint8_t y){
    renderCursor(x, y);
}

void Cursor::setCursorX(uint8_t x){
    renderCursor(x, posY);
}

void Cursor::setCursorY(uint8_t y){
    renderCursor(posX, y);
}

uint8_t Cursor::getCursorX(){
    return posX;
}

uint8_t Cursor::getCursorY(){
    return posY;
}

void Cursor::renderCursor(uint8_t x, uint8_t y){
    if(posX == 0 && posY == 0 && y == 0){
	posX = x;
	posY = y;
	invertBitColor(80 * posY + posX);
    } else {
	invertBitColor(80 * posY + posX);
	posX = x;
	posY = y;
	invertBitColor(80 * posY + posX);
    }
}