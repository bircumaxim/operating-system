#include <std/printf.h>

void printf(char* str){
    for(int i = 0; str[i] != '\0'; i++){
        switch(str[i]){
            case '\n':
                cursorX = 0;
                cursorY++;
                break;
            default:
		setBit(80 * cursorY + cursorX, str[i]);
                cursorX++;
                break;
        }

        if(cursorX >= 80){
            cursorX = 0;
            cursorY++;
        }

        if(cursorY >= 25){
            clear();
        }
    }
}

void clear(){
    for(cursorY = 0; cursorY < 25; cursorY++){
	for(cursorX = 0; cursorX < 80; cursorX++){
	    setBit(80 * cursorY + cursorX, ' ');   
	}
    }
    cursorX = 0;
    cursorY = 0;
}

void printfHex8(uint8_t key){
    char* str = "0x00";
    char* hex = "0123456789ABCDEF";
    str[2] = hex[(key >> 4) & 0xF];
    str[3] = hex[key & 0xF];
    printf(str);
    
}

void printfHex16(uint16_t key){
    printfHex8((key >> 8) & 0xFF);
    printfHex8( key & 0xFF);
}

void printfHex32(uint32_t key){
    printfHex8((key >> 24) & 0xFF);
    printfHex8((key >> 16) & 0xFF);
    printfHex8((key >> 8) & 0xFF);
    printfHex8( key & 0xFF);
}