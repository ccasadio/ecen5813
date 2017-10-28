# -*- MakeFile -*-


PLATFORM ?= HOST
SOURCES  = conversion debug main memory
HEADERS  = core_cm0plus core_cm4 core_cm4_simd core_cmFunc core_cmInstr MKL25Z4 system_MKL25Z4
TESTS = testtest1 testtest2


ifeq ($(PLATFORM), KL25Z)
CPPFLAGS = 
LDFLAGS = 
INCLUDE_PATHS = ../include/common ../include/kl25z
CC = arm-none-gnueabi-gcc

else ifeq ($(PLATFORM), BBB)
CPPFLAGS = 
INCLUDE_PATHS = ../include/CMSIS ../include/common
CC = arm-linux-gnueabihf-gcc

else
CPPFLAGS = 
INCLUDE_PATHS = ../include/common
CC = gcc

endif

compilerflags = -Wall -Werror -g -std=c99 $(CFLAGS)
testPath = tests/

#link together all object files
project1.elf: $(addsuffix .o, $(SOURCES))
	$(CC) $^ -o $@ $(compilerflags) $(addprefix -I,$(INCLUDE_PATHS)) $(addprefix -D, $(CPPFLAGS)) -Xlinker -Map=project1.map

%.i: %.c
	$(CC) $< -o $@ -E $(compilerflags) $(addprefix -I,$(INCLUDE_PATHS)) $(addprefix -D, $(CPPFLAGS))

%.asm: %.c
	$(CC) $< -o $@ -S $(compilerflags) $(addprefix -I,$(INCLUDE_PATHS)) $(addprefix -D, $(CPPFLAGS))

%.o: %.c
	$(CC) $< -o $@ -c $(compilerflags) $(addprefix -I,$(INCLUDE_PATHS)) $(addprefix -D, $(CPPFLAGS))

%.dep: %.c
	$(CC) $< -o $@ -M $(compilerflags) $(addprefix -I,$(INCLUDE_PATHS)) $(addprefix -D, $(CPPFLAGS))

#header file dependency for like named c files
%.c: %.h
	touch $@

.PHONY: compile-all
compile-all: $(addsuffix .o, $(SOURCES))

#helper function to delete all object  files
.PHONY: clean
clean: 
	rm -f $(addsuffix .o, $(SOURCES)) $(addsuffix .out, $(SOURCES)) $(addsuffix .asm, $(SOURCES)) $(addsuffix .i, $(SOURCES)) $(addsuffix .map, $(SOURCES)) $(addsuffix .elf, $(SOURCES))

.PHONY: test-all


test_%: %.o
	$(CC) $(addprefix $(testPath),$(addsuffix .c, $@)) $< -lcmocka $(compilerflags) $(addprefix -I,$(INCLUDE_PATHS))

test-optimize%: 
	rm -f optimizationReport.txt
	make clean
	make test CFLAGS=-O$*
	echo -e "optimization level " $* "\n" &>> optimizationReport.txt
	./a.out &>> optimizationReport.txt
	echo "\n" &>> optimizationReport.txt
	ls -l --block-size=KB a.out &>> optimizationReport.txt



.PHONY: optimize
optimize: $(addprefix test-optimize,1 2 3 s fast)
