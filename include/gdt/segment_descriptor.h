#ifndef __OPERATING_SYSTEM__GDT__SEGMENT_DESCRIPTOR_H
#define __OPERATING_SYSTEM__GDT__SEGMENT_DESCRIPTOR_H

#include <std/types.h>

class SegmentDescriptor{
    private:
	uint16_t limit_lo;
	uint16_t base_lo;
	uint8_t base_hi;
	uint8_t type;
	uint8_t flags_limit_hi;
	uint8_t base_vhi;
    public:
	SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);
	uint32_t getBase();
	uint32_t getLimit();
} __attribute__((packed));
    

#endif