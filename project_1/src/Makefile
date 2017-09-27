# -*- MakeFile -*-

#target: dependencies
#	action


#VARIABLE?=default_value_if_not_already_set
CC
CFLAGS
CPPFLAGS
LDFLAGS
PLATFORM
SOURCES
INCLUDES

files_platform_independent :=
files_platform_bbb :=
files_platform_kl25z :=

#dummy target to make executibles for all 3 platforms
all: BBB_Executible Freedom_Executible Host_Executible

#link together all BBB object files
main.elf: *_BBB.o
	$(CC) $^ -o $@ $(CFLAGS)

#cross compile all .c files into object files (with a _BBB.o name) for the BBB platform 
%_BBB.o: %.c %.h
	arm-linux-gnueabihf-gcc $< -o $@


#link together all Freedom object files
Freedom_Executible: *_Freedom.o
	gcc $^ -o $@

#cross compile all .c files into object files (with a _Freedom.o name) for the Freedom Board platform 
%_Freedom.o: %.c %.h
	arm-none-gnueabi-gcc $< -o $@

#link together all Host object files
Host_Executible: *_Host.o
	gcc $^ -o $@

#compile all .c files into object files (with a _Host.o name) 
%_Host.o: %.c %.h
	gcc $< -o $@

#helper function to delete all object  files
.PHONY: clean
clean: 
	rm -f *.o *.out *.asm *.i *.map
