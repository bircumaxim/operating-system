#include <std/video_memory.h>

void invertBitColor(int bitIndex){
    VideoMemory[bitIndex] = ((VideoMemory[bitIndex] & 0xF000) >> 4) 
			    | ((VideoMemory[bitIndex] & 0x0F00) << 4)
			    | (VideoMemory[bitIndex] & 0x00FF);
}

void setBit(int bitIndex, char data){
    VideoMemory[bitIndex] = (VideoMemory[bitIndex] & 0xFF00) | data;
}
	