#include <std/types.h>
#include <gdt/gdt.h>
#include <hdwcom/interrupt_manager.h>
#include <drivers/driver_manager.h>
#include <drivers/keyboard.h>
#include <drivers/mouse.h>
#include <event/key_event_handler.h>
#include <terminal.h>
#include <drivers/vga.h>

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors(){
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}

extern "C" void kernelMain(void* multiboot_structure, uint32_t magicnumber){    
    //Init global descriptor table
    GlobalDescriptorTable gdt;
    
    //Managers
    InterruptManager interrupts(&gdt);    
    DriverManager drvManager;

    //Keyboard Driver
    KeyboardDriver keyboard(&interrupts);
    drvManager.addDriver(&keyboard);
    
    //Mouse Driver
    MouseDriver mouse(&interrupts);
    drvManager.addDriver(&mouse);
    
    //VGA
    VideoGraphicsArray vga;
    
    //DriverManager
    drvManager.activateAllDivers();
    
    //Activate interrupts
    interrupts.activate();
    
    vga.setMode(320,200,8);
    vga.fillRectangle(0,0,320,200,0x00,0x00,0xA8);
    
    Terminal terminal;
    
    while(1);
}
