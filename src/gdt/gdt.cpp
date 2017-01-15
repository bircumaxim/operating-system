#include <gdt/gdt.h>

GlobalDescriptorTable::GlobalDescriptorTable()
    :nullSegmentSelector(0,0,0), 
    unusedSegmentSelector(0,0,0), 
    codeSegmentSelector(0, 64*1024*1024, 0x9A),
    dataSegmentSelector(0, 64*1024*1024, 0x92){
    
    uint32_t i[2];
    i[1] = (uint32_t)this;
    i[0] = sizeof(GlobalDescriptorTable) << 16;
    asm volatile("lgdt (%0)": :"p" (((uint8_t *) i)+2));
}

GlobalDescriptorTable::~GlobalDescriptorTable(){ }

uint16_t GlobalDescriptorTable::getDataSegment(){
    return (uint8_t*)&dataSegmentSelector - (uint8_t*)this;
}

uint16_t GlobalDescriptorTable::getCodeSegment(){
    return (uint8_t*)&codeSegmentSelector - (uint8_t*)this;
}
