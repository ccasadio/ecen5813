# -*- MakeFile -*-

#target: dependencies
#	action

#dummy target to make executibles for all 3 platforms
all: BBB_Executible Freedom_Executible Host_Executible

#link together all BBB object files
BBB_Executible: *_BBB.o
	gcc $^ -o $@

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

#helper function to delete all object files
clean: 
	rm -f *.o
