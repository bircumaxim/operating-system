#ifndef __OPERATING_SYSTEM__HDWCOM__PORT__SLOW_PORT_8_H
#define __OPERATING_SYSTEM__HDWCOM__PORT__SLOW_PORT_8_H

#include <std/types.h>
#include <hdwcom/port/port_8.h>

class Port8BitSlow : public Port8Bit{
    public:
	Port8BitSlow(uint16_t portNumber);
	~Port8BitSlow();
	virtual void write(uint8_t data);
};


#endif