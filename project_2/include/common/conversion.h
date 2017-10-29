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
* @file conversion.h
* @brief Basic data manipulation functions
* 
*
* @author Christian Casadio
* @date Oct. 2, 2017
* @version 1.0
*
*/
#ifndef _GAURD_INCLUDE_COMMON_CONVERSION_H
#define _GAURD_INCLUDE_COMMON_CONVERSION_H

#include <stdint.h>

/**
 * @brief function to convert data from a standard integer type into an ASCII​ string
 * 
 * This function takes in a signed 32 bit integer (data), a pointer (ptr), and an unsigned 
 * 32 bit integer (base), converts data from a standard integer type into an ASCII​ string
 * that shows the number in the form of a base base number. The string will be copied to 
 * the pointer passed into the function and the length of the string will be returned minus
 * the null terminator.
 *
 * @param data the decimal number that is going to be converted
 * @param ptr the pointer to where the string will be stored
 * @param base the base of the converted number
 * 
 * @return length of string
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief function to convert data from a standard ASCII​ string type into an integer
 * 
 * This function takes in a signed 32 bit integer (data), a pointer (ptr), and an unsigned 
 * 32 bit integer (base), converts data from a standard integer type into an ASCII​ string
 * that shows the number in the form of a base base number. The string will be copied to 
 * the pointer passed into the function and the length of the string will be returned minus
 * the null terminator.
 *
 * @param digits the number of digits in the number
 * @param ptr the pointer to the string
 * @param base the base of the number
 * 
 * @return converted number
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
 * @brief function to convert a set of 32 bit data from big endian to little endian
 * 
 *
 * @param length the number of data
 * @param data pointer to the first data point
 * 
 * @return 0 for success and not 0 for failure
 */
uint8_t big_to_little32(uint32_t * data, uint32_t length);

/**
 * @brief function to convert a set of 32 bit data from little endian to big endian
 * 
 *
 * @param length the number of data
 * @param data pointer to the first data point
 * 
 * @return 0 for success and not 0 for failure
 */
uint8_t little_to_big32(uint32_t * data, uint32_t length);

#endif