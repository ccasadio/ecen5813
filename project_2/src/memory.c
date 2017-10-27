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
* @file memory.c
* @brief memory manipulation functions
*
* 
* @author Christian Casadio
* @date Oct. 1, 2017
* @version 1.0
*
*/

#include "memory.h"
#include <stdio.h>

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	/* check for null ptr */
	if(!src)
	{
		return src;
	}

	/* check for null ptr */
	if(!dst)
	{
		return dst;
	}

	/* check for zero length */
	if(!length)
	{
		return dst;
	}

	uint8_t i;

	/* if pointer addresses are the same then we're already done */
	if(src == dst)
	{
		return dst;
	}
	

	/* choose whether to work backwards or forwards to avoid corrupting overlapping data */
	if(src > dst)
	{
		for(i = 0; i < length; i++)
		{
			*(dst + i) = *(src + i);
		}
	}
	else
	{
		for(i = 1; i < length + 1; i++)
		{	
			*(dst + length - i) = *(src + length - i);
		}
	}

	return dst;
}

uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
	/* check for null ptr */
	if(!src)
	{
		return src;
	}

	/* check for null ptr */
	if(!dst)
	{
		return dst;
	}

	/* check for zero length */
	if(!length)
	{
		return dst;
	}

	uint8_t i;
	for(i = 0; i < length; i++)
	{
		*(dst + i) = *(src + i);
	}

	return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	/* check for null ptr */
	if(!src)
	{
		return src;
	}

	/* check for zero length */
	if(!length)
	{
		return dst;
	}

	uint8_t i;
	for(i = 0; i < length; i++)
	{
		*(src + i) = value;
	}

	return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
	return my_memset(src, length, 0);
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
	/* check for null ptr */
	if(!src)
	{
		return src;
	}

	/* check for zero length */
	if(!length)
	{
		return dst;
	}

	uint8_t tmp;
	uint8_t i;
	for(i = 0; i < length/2; i++)
	{
		tmp = *(src + i);
		*(src + i) = *(src + length - 1 - i);
		*(src + length - 1 - i) = tmp;
	}
	return src;
}


uint32_t* reserve_words(size_t length)
{
	return (uint32_t *)malloc(length*sizeof(uint32_t));
}

void free_words(uint32_t * src)
{
	free(src);
}
