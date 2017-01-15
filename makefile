GCCPARAMS = -m32 -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = bin/obj/main.o \
	  bin/obj/loader.o \
	  bin/obj/terminal.o \
	  bin/obj/gdt/gdt.o \
	  bin/obj/event/key_event_handler.o \
	  bin/obj/event/mouse_event_handler.o \
	  bin/obj/gdt/segment_descriptor.o \
	  bin/obj/hdwcom/port/port.o \
	  bin/obj/hdwcom/port/port_8.o \
	  bin/obj/hdwcom/port/port_16.o \
	  bin/obj/hdwcom/port/port_32.o \
	  bin/obj/hdwcom/port/slow_port_8.o \
	  bin/obj/hdwcom/interruptsstubs.o \
	  bin/obj/hdwcom/interrupt_handler.o \
	  bin/obj/hdwcom/interrupt_manager.o \
	  bin/obj/drivers/driver.o \
	  bin/obj/drivers/driver_manager.o \
	  bin/obj/drivers/mouse.o \
	  bin/obj/drivers/keyboard.o \
	  bin/obj/drivers/vga.o \
	  bin/obj/std/printf.o \
	  bin/obj/std/video_memory.o \
	  
	
bin/obj/%.o: src/%.cpp
	mkdir -p $(@D)
	g++ $(GCCPARAMS) -o $@ -c $<

bin/obj/%.o: src/%.s
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<

bin/kernel.bin: linker.ld $(objects)
	mkdir -p $(@D)
	ld $(LDPARAMS) -T $< -o $@ $(objects)
	
kernel.iso: bin/kernel.bin
	mkdir -p $(@D) iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp bin/kernel.bin iso/boot/kernel.bin
	echo 'set timeout=0'                      > iso/boot/grub/grub.cfg
	echo 'set default=0'                     >> iso/boot/grub/grub.cfg
	echo ''                                  >> iso/boot/grub/grub.cfg
	echo 'menuentry "My Operating System" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin'    >> iso/boot/grub/grub.cfg
	echo '  boot'                            >> iso/boot/grub/grub.cfg
	echo '}'                                 >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=iso/kernel.iso iso
	rm -rf iso/boot	

run: kernel.iso
	(killall VirtualBox & sleep 1) || true
	VirtualBox --startvm "OS"

	
.PHONY: clean
clean:
	rm -rf bin iso
