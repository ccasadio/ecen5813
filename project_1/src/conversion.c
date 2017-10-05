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

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint8_t length ;

	int8_t i;
	for(i = length - 1; i > -1; i--)
	{
		if(data%base > 9)
		{
			*(ptr + i) = ascii_A + data%base - 10;
		}
		else
		{
			*(ptr + i) = ascii_0 + data%base;
		}
		
		data /= base;
	}
	/* add null terminating character */
	*(ptr + length) = 0;

}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	uint32_t number = 0;
	uint32_t temp;

	uint8_t i;
	uint8_t j;
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

	return number;
}


int8_t big_to_little32(uint32_t * data, uint32_t length)
{
	uint32_t i;
	for(i = 0; i < length; i++)
	{
		*(data + i) = *((uint32_t*) my_reverse(*(data + i), 4));
	}

	return 0;
}


int8_t little_to_big32(uint32_t * data, uint32_t length)
{
	uint32_t i;
	for(i = 0; i < length; i++)
	{
		*(data + i) = *((uint32_t*) my_reverse(*(data + i), 4));
	}

	return 0;
}
