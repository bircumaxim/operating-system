#ifndef __OPERATING_SYSTEM__HDWCOM__PORT__PORT_H
#define __OPERATING_SYSTEM__HDWCOM__PORT__PORT_H

#include <std/types.h>

class Port{
    protected: 
	uint16_t portNumber;
	Port(uint16_t portNumber);
	~Port();
    
};

#endif