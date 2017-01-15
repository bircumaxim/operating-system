#include <hdwcom/port/port_8.h>

Port8Bit::Port8Bit(uint16_t portNumber) : Port(portNumber) { }

Port8Bit::~Port8Bit() { }

void Port8Bit::write(uint8_t data){
    __asm__ volatile("outb %0, %1" : : "a" (data), "Nd" (portNumber));
}

uint8_t Port8Bit::read(){
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (portNumber));
    return result;
}
