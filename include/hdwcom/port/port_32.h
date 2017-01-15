#ifndef __OPERATING_SYSTEM__HDWCOM__PORT__PORT_32_H
#define __OPERATING_SYSTEM__HDWCOM__PORT__PORT_32_H

#include <std/types.h>
#include <hdwcom/port/port.h>

class Port32Bit : public Port{
    public:
	Port32Bit(uint16_t portNumber);
	~Port32Bit();
	virtual void write(uint32_t data);
	virtual uint32_t read();
};

#endif