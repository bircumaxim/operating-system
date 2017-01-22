#include <std/types.h>
#include <gdt/gdt.h>
#include <hdwcom/interrupt_manager.h>
#include <drivers/driver_manager.h>
#include <drivers/keyboard.h>
#include <drivers/mouse.h>
#include <event/key_event_handler.h>
#include <shell.h>
#include <drivers/vga.h>
#include <apps/writter.h>
#include <apps/calculator.h>
#include <apps/paint.h>

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors(){
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}

Shell shell;
Writter writter;
Calculator calculator;


VideoGraphicsArray vga;
Paint paint(&vga);

void initApps(){
    shell.addApp(&writter);
    shell.addApp(&calculator);
    shell.addApp(&paint);
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
    
    
    
    //DriverManager
    drvManager.activateAllDivers();
    
    //Activate interrupts
    interrupts.activate();
    
        
    initApps();
    
    while(true);
}
