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
* @file debug.c
* @brief debugging tools
* 
*
* @author Christian Casadio
* @date Oct. 4, 2017
* @version 1.0
*
*/

#include "debug.h"
#include <stdio.h>

void print_memory(uint8_t * start, uint32_t length)
{
	uint32_t i;

	for(i = 0; i < length; i++)
	{
		printf("%X ", *(start + i));
	}
	
	printf("\n");
}
