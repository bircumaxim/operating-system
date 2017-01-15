#ifndef __OPERATING_SYSTEM__HDWCOM__PORT__PORT_16_H
#define __OPERATING_SYSTEM__HDWCOM__PORT__PORT_16_H

#include <std/types.h>
#include <hdwcom/port/port.h>

class Port16Bit : public Port{
    public:
	Port16Bit(uint16_t portNumber);
	~Port16Bit();
	virtual void write(uint16_t data);
	virtual uint16_t read();
};

#endif