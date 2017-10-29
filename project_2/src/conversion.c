/*****************************************************************************
* Copyright (C) 2017 by Christian Casadio
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it as they wish. Christian Casadio is not 
* liable for any misuse of or damages caused by use of this material.
*
*****************************************************************************/
/**
* @file conversion.c
* @brief Basic data manipulation functions
*
*
* @author Christian Casadio
* @date Oct. 2, 2017
* @version 1.0
*
*/

#include "conversion.h"
#include "memory.h"

const uint8_t ascii_0 = 48;
const uint8_t ascii_A = 65;
const uint8_t ascii_neg = 45;

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint8_t length = 0;

	if(data == 0)
	{
		*ptr = ascii_0;
		*(ptr + 1) = 0;
		return 1;
	}

	if(data < 0)
	{
		//negative
		*ptr = ascii_neg;
		ptr++;
		data *= -1;
	}

	while(data > 0)
	{
		if(data%base > 9)
		{
			*(ptr + length) = ascii_A + data%base - 10;
		}
		else
		{
			*(ptr + length) = ascii_0 + data%base;
		}
		length++;

		data /= base;
	}

	/* reverse */
	my_reverse(ptr, length);

	/* add null terminating character */
	*(ptr + length) = 0;

	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int32_t number = 0;
	uint32_t temp;
	int8_t isNeg = 1;

	uint8_t i;
	uint8_t j;

	if(*ptr == ascii_neg)
	{
		ptr++;
		isNeg = -1;
	}

	for(i = 0; i < digits; i++)
	{
		temp = *(ptr + i);

		if(temp > 64)
		{
			temp -= ascii_A;
			temp += 10;
		}
		else
		{
			temp -= ascii_0;
		}

		/* power */
		for(j = 0; j < digits - i - 1; j++)
		{
			temp *= base;
		}

		number += temp;
	}

	return number*isNeg;
}


uint8_t big_to_little32(uint32_t * data, uint32_t length)
{
	if(!data)
	{
		return 1;
	}

	uint32_t i;
	for(i = 0; i < length; i++)
	{
		*(data + i) = *((uint32_t*) my_reverse(((uint8_t*)(data + i)), 4));
	}

	return 0;
}


uint8_t little_to_big32(uint32_t * data, uint32_t length)
{
	if(!data)
	{
		return 1;
	}
	
	uint32_t i;
	for(i = 0; i < length; i++)
	{
		*(data + i) = *((uint32_t*) my_reverse(((uint8_t*)(data + i)), 4));
	}

	return 0;
}
