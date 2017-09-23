#include <stdio.h>

void main()
{
	char a[] = {0xee, 0x12, 0x77, 0xbe, 0x66, 0x54, 0x33, 0xf0};

	unsigned char *ptr = &a[0];
	*ptr = 0xf1 & 127;
	ptr++;
	*ptr += 17;
	ptr += 2;
	*ptr = 15 % 4;
	ptr--;
	*ptr >>= 4;
	ptr = &a[5];
	int q = ((1<<5)|(4<<2));
	*ptr = q;
	*((char*)&a[7]) = 22;

	int i;
	for(i = 0; i < 8; i++)
	{
		printf("0x%02x\n",a[i]);
	}
}
