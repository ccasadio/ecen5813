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
* @file memory.h
* @brief memory manipulation functions
*
* 
* 
*
* @author Christian Casadio
* @date Oct. 1, 2017
* @version 1.0
*
*/

#ifndef _GAURD_INCLUDE_COMMON_MEMORY_H
#define _GAURD_INCLUDE_COMMON_MEMORY_H

#include <stdint.h>
#include <stdlib.h>

/**
 * @brief function to copy length bytes from the source location (src) to the destination (dst)
 * 
 * This function takes two byte pointers (one source and one destination) and a length of bytes to
 * copy from the source location to the destination. 
 *
 * @param src pointer to first byte to be copied
 * @param dst pointer to location where bytes will be copied
 * @param length number of bytes
 * 
 * @return a pointer to the destination (dst)
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief function to copy length bytes from the source location (src) to the destination (dst)
 * 
 * This function takes two byte pointers (one source and one destination) and a length of bytes to
 * copy from the source location to the destination. The behavior is undefined if there is overlap of
 * source and destination. Copy should still occur, but will likely corrupt your data.
 *
 * @param src pointer to first byte to be copied
 * @param dst pointer to location where bytes will be copied
 * @param length number of bytes
 *
 * @return a pointer to the destination (dst)
 */
uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief function to set length bytes starting from the source location (src) to a given value (value)
 * 
 * This function takes a pointer to a source memory location, a length in bytes and sets all bytes 
 * of that memory region to a given value.
 *
 * @param src pointer to first byte to be set
 * @param value value to set given bytes to
 * @param length number of bytes
 *
 * @return a pointer to the source (src)
 */
int8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief function to set length bytes starting from the source location (src) to 0
 * 
 * This function takes a pointer to a source memory location, a length in bytes and sets all bytes 
 * of that memory region to 0.
 *
 * @param src pointer to first byte to be set
 * @param length number of bytes
 *
 * @return a pointer to the source (src)
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief function to reverse the order of length bytes starting from the source location (src)
 * 
 * This function takes a pointer to a source memory location, a length in bytes, reverses the
 * order of those bytes and returns a pointer to src.
 *
 * @param src pointer to first byte
 * @param length number of bytes
 *
 * @return a pointer to the source (src)
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief function to allocate dynamic memory.
 * 
 * This function takes a length in bytes, allocates that much memory and returns a pointer to
 * the begening of that section of memory.
 *
 * @param length number of bytes
 *
 * @return a pointer to the beginning of the memory section
 */
uint32_t * reserve_words(size_t length);

/**
 * @brief function to free dynamic memory allocated by reserve_words
 * 
 * This function takes a pointer to a source memory location that was allocated by reserve_words
 * and frees that memory for future use.
 *
 * @param src pointer to first byte
 *
 * @return void
 */
void free_words(uint32_t * src);

#endif