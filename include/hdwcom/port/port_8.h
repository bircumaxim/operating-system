#ifndef __OPERATING_SYSTEM__HDWCOM__PORT__PORT_8_H
#define __OPERATING_SYSTEM__HDWCOM__PORT__PORT_8_H

#include <std/types.h>
#include <hdwcom/port/port.h>

class Port8Bit : public Port{
    public:
	Port8Bit(uint16_t portNumber);
	~Port8Bit();
	virtual void write(uint8_t data);
	virtual uint8_t read();
};

#endif