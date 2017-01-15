#include <hdwcom/port/port_32.h>

Port32Bit::Port32Bit(uint16_t portNumber) : Port(portNumber) { }

Port32Bit::~Port32Bit() { }

void Port32Bit::write(uint32_t data){
    __asm__ volatile("outl %0, %1" : : "a" (data), "Nd" (portNumber));
}

uint32_t Port32Bit::read(){
    uint32_t result;
    __asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (portNumber));
    return result;
}