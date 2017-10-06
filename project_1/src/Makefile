# -*- MakeFile -*-

#target: dependencies
#	action



PLATFORM ?= HOST
SOURCES  = conversion debug main memory project1 
HEADERS  = core_cm0plus core_cm4 core_cm4_simd core_cmFunc core_cmInstr MKL25Z4 system_MKL25Z4



ifeq ($(PLATFORM), KL25Z)
CFLAGS   = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = 
LDFLAGS = 
INCLUDE_PATHS = ../include/common ../include/kl25z
CC = arm-none-gnueabi-gcc

else ifeq ($(PLATFORM), BBB)
CFLAGS   = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = 
INCLUDE_PATHS = ../include/CMSIS ../include/common
CC = arm-linux-gnueabihf-gcc

else
CFLAGS   = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = 
INCLUDE_PATHS = ../include/common
CC = gcc

endif

#link together all object files
project1.elf: $(addsuffix .o, $(SOURCES))
	$(CC) $^ -o $@ $(CFLAGS) $(addprefix -I,$(INCLUDE_PATHS)) $(addprefix -D, $(CPPFLAGS))

%.i: %.c
	$(CC) $< -o $@ -E $(CFLAGS) $(addprefix -I,$(INCLUDE_PATHS)) $(addprefix -D, $(CPPFLAGS))

%.asm: %.c
	$(CC) $< -o $@ -S $(CFLAGS) $(addprefix -I,$(INCLUDE_PATHS)) $(addprefix -D, $(CPPFLAGS))

%.o: %.c
	$(CC) $< -o $@ -c $(CFLAGS) $(addprefix -I,$(INCLUDE_PATHS)) $(addprefix -D, $(CPPFLAGS))

.PHONY: compile-all
compile-all: $(addsuffix .o, $(SOURCES))

#helper function to delete all object  files
.PHONY: clean
clean: 
	rm -f $(addsuffix .o, $(SOURCES)) $(addsuffix .out, $(SOURCES)) $(addsuffix .asm, $(SOURCES)) $(addsuffix .i, $(SOURCES)) $(addsuffix .map, $(SOURCES)) $(addsuffix .elf, $(SOURCES))
