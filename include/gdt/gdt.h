#ifndef __OPERATING_SYSTEM__GDT__GDT_H
#define __OPERATING_SYSTEM__GDT__GDT_H

#include <gdt/segment_descriptor.h>
#include <std/types.h>

class GlobalDescriptorTable{
    public:
	SegmentDescriptor nullSegmentSelector;
	SegmentDescriptor unusedSegmentSelector;
	SegmentDescriptor codeSegmentSelector;
	SegmentDescriptor dataSegmentSelector;
	
	GlobalDescriptorTable();
	~GlobalDescriptorTable();
	
	uint16_t getCodeSegment();
	uint16_t getDataSegment();
};

#endif