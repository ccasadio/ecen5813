#define SUCCESS ('s')
#define FAIL_USER_INPUT ('u')

char reverse(char *str, int length)
{
	if(length < 1)
	{
		return FAIL_USER_INPUT;
	}
	else if(length == 1)
	{
		return SUCCESS;
	}

	char temp;
	int i;
	
	for(i = 0; i < length/2; i++)
	{
		temp = *(str + i);
		*(str + i) = *(str + length - 1 - i);
		*(str + length - 1 - i) = temp;
	}

	return SUCCESS;
}
