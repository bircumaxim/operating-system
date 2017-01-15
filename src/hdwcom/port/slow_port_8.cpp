#include <hdwcom/port/slow_port_8.h>

Port8BitSlow::Port8BitSlow(uint16_t portNumber) : Port8Bit(portNumber) { }

Port8BitSlow::~Port8BitSlow() { }

void Port8BitSlow::write(uint8_t data){
    __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a" (data), "Nd" (portNumber));
} 
