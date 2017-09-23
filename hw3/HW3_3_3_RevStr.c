#include <stdio.h>
#include "reverse.c"


int main()
{

	char str1[] = "This is a string.";
	int length1 = 17;

	char str2[] = "some NUMmbers12345";
	int length2 = 18;

	char str3[] = "Does it reverse \n\0\t correctly?";
	int length3 = 30;

	printf("String1: %s\n", str1);
	reverse(str1, length1);
	printf("reverse: %s\n", str1);

	printf("String2: %s\n", str2);
	reverse(str2, length2);
	printf("reverse: %s\n", str2);

	printf("String3: %s\n", str3);
	reverse(str3, length3);
	printf("reverse: %s\n", str3);

}
