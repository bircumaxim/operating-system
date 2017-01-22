#ifndef __OPERATING_SYSTEM__DRIVERS__VGA_H
#define __OPERATING_SYSTEM__DRIVERS__VGA_H

#include <std/types.h>
#include <hdwcom/port/port_8.h>

class VideoGraphicsArray{
    protected:
	Port8Bit miscPort;
	Port8Bit crtcIndexPort;
	Port8Bit crtcDataPort;
	Port8Bit sequencerIndexPort;
	Port8Bit sequencerDataPort;
	Port8Bit graphicsControllerIndexPort;
	Port8Bit graphicsControllerDataPort;
	Port8Bit attributeControllerIndexPort;
	Port8Bit attributeControllerReadPort;
	Port8Bit attributeControllerWritePort;
	Port8Bit attributeControllerResetPort;
	
	
	void writeRegisters(uint8_t* registers);
	uint8_t* getFrameBufferSegment();
	
	virtual uint8_t getColorIndex(uint8_t r, uint8_t g, uint8_t b);
	
    public:
	VideoGraphicsArray();
    
	virtual bool supportsMode(uint32_t width, uint32_t height, uint32_t colordepth);
	virtual bool setMode(uint32_t width, uint32_t height, uint32_t colordepth);
	virtual void putPixel(int32_t x, int32_t y,  uint8_t r, uint8_t g, uint8_t b);
	virtual void putPixel(int32_t x, int32_t y, uint8_t colorIndex);
	bool pixelIsOfColor(int32_t x, int32_t y ,uint8_t r, uint8_t g, uint8_t b);
	virtual void fillRectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint8_t r, uint8_t g, uint8_t b);
    
};

#endif