# -*- MakeFile -*-

#target: dependencies
#	action



PLATFORM ?= HOST
SOURCES  = conversion debug main memory project1 
HEADERS  = core_cm0plus core_cm4 core_cm4_simd core_cmFunc core_cmInstr MKL25Z4 system_MKL25Z4



ifeq ($(PLATFORM), KL25Z)
    CFLAGS   = -Wall -Werror -g -O0 -std=c99
    CPPFLAGS 
    LDFLAGS 
    INCLUDE_PATHS = ../include/common ../include/kl25z
    CC = arm-none-gnueabi-gcc

else ifeq ($(PLATFORM), BBB)
    CFLAGS   = -Wall -Werror -g -O0 -std=c99
    CPPFLAGS 
    INCLUDE_PATHS = ../include/CMSIS ../include/common
    CC = arm-linux-gnueabihf-gcc

else
    CFLAGS   = -Wall -Werror -g -O0 -std=c99
    CPPFLAGS 
    INCLUDE_PATHS = ../include/common
    CC = gcc

endif


#link together all BBB object files
main.elf: $(addsuffix .o, $(SOURCES))
	$(CC) $^ -o $@ $(CFLAGS) -I $(INCLUDE_PATHS) -D $(CPPFLAGS) 

%.i: %.c %.h
	$(CC) $< -0 $@ -E $(CFLAGS) -I $(INCLUDE_PATHS) -D $(CPPFLAGS) 

%.asm: %.c %.h
	$(CC) $< -0 $@ -S $(CFLAGS) -I $(INCLUDE_PATHS) -D $(CPPFLAGS) 

%.o: %.c %.h
	$(CC) $< -0 $@ -c $(CFLAGS) -I $(INCLUDE_PATHS) -D $(CPPFLAGS) 

.PHONY: compile-all
compile-all: $(addsuffix .o, $(SOURCES))

#cross compile all .c files into object files (with a _BBB.o name) for the BBB platform 
%_BBB.o: %.c %.h
	arm-linux-gnueabihf-gcc $< -o $@

#helper function to delete all object  files
.PHONY: clean
clean: 
	rm -f $(addsuffix .o, $(SOURCES)) $(addsuffix .out, $(SOURCES)) $(addsuffix .asm, $(SOURCES)) $(addsuffix .i, $(SOURCES)) $(addsuffix .map, $(SOURCES))
