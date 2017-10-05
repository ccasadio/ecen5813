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
* @file debug.h
* @brief debugging tools
* 
*
* @author Christian Casadio
* @date Oct. 4, 2017
* @version 1.0
*
*/

#ifndef _GAURD_INCLUDE_COMMON_DEBUG_H
#define _GAURD_INCLUDE_COMMON_DEBUG_H

#include <stdint.h>

/**
 * @brief function to print n bytes
 * 
 * This function prints length bytes starting from start.
 *
 * @param start pointer to the first byte to be printed
 * @param length number of bytes to be printed
 *
 * @return void
 */
void print_memory(uint8_t * start, uint32_t length);

#endif