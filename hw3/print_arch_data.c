#include <stdio.h>
#include <stdint.h>

void print_arch_data()
{
	printf("sizeof char: %d\n",sizeof(char));
	printf("sizeof int: %d\n",sizeof(int));
	printf("sizeof float: %d\n",sizeof(float));
	printf("sizeof double: %d\n",sizeof(double));
	printf("sizeof short: %d\n",sizeof(short));
	printf("sizeof long: %d\n",sizeof(long));
	printf("sizeof long int: %d\n",sizeof(long int));
	printf("sizeof long long: %d\n",sizeof(long long));
	printf("sizeof int8_t: %d\n",sizeof(int8_t));
	printf("sizeof uint8_t: %d\n",sizeof(uint8_t));
	printf("sizeof uint16_t: %d\n",sizeof(uint16_t));
	printf("sizeof uint32_t: %d\n",sizeof(uint32_t));
	printf("sizeof char*: %d\n",sizeof(char*));
	printf("sizeof int*: %d\n",sizeof(int*));
	printf("sizeof float*: %d\n",sizeof(float*));
	printf("sizeof void*: %d\n",sizeof(void*));
	printf("sizeof void**: %d\n",sizeof(void**));
	printf("sizeof int8_t*: %d\n",sizeof(int8_t*));
	printf("sizeof int16_t*: %d\n",sizeof(int16_t*));
	printf("sizeof int32_t*: %d\n",sizeof(int32_t*));
	printf("sizeof size_t: %d\n",sizeof(size_t));
}
