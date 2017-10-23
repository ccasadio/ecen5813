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
* @file cbuff.h
* @brief circular buffer data structure
*
* 
* 
*
* @author Christian Casadio
* @date Oct. 19 2017
* @version 1.0
*
*/

#include <stdint.h>

typedef struct
{
	uint8_t *buf;
	uint8_t *head;
	uint8_t *tail;
	uint16_t size;
} CB_t;

typedef enum
{
	Success = 0;
	BufferFull;
	BufferEmpty;
	NullPointer;
	NoLength;
	BufferAllocationFailure;
} CB_Status_t;



/**
 * @brief function to add an item to the given circular buffer.
 * 
 * 
 *
 * @param cb pointer to circular buffer
 * @param data item to be stored in the circular buffer
 *
 * @return circular buffer status code
 */
CB_Status_t CB_buffer_add_item(CB_t* cb, uint8_t data);



/**
 * @brief function to remove an item from the circular buffer
 * 
 * This function will remove an item from the circular buffer and return a buffer status code 
 * based on what occurred during its execution. 
 *
 * @param cb pointer to circular buffer
 * @param buff pointer to where removed item should be stored
 *
 * @return circular buffer status code
 */
CB_Status_t CB_buffer_remove_item(CB_t* cb, uint8_t* buff);



/**
 * @brief function to check if a given circular buffer is full
 * 
 * This function will return a success (0) if the circular buffer is empty or this function 
 * will return BufferFull if the circular buffer is full.
 *
 * @param cb pointer to circular buffer
 *
 * @return circular buffer status code
 */
CB_Status_t CB_is_full(CB_t* cb);



/**
 * @brief function to check if a given circular buffer is empty
 * 
 * This function will return a success (0) if the circular buffer is empty or this function 
 * will return BufferEmpty if the circular buffer is full.
 *
 * @param cb pointer to circular buffer
 *
 * @return circular buffer status code
 */
CB_Status_t CB_is_empty(CB_t* cb);



/**
 * @brief function to look at the nth item from the tail of the circular buffer  
 * 
 * This function looks at the nth item from the tail of the circular buffer and return a 
 * status code.
 *
 * @param cb pointer to circular buffer
 * @param peekDepth number of items from the tail
 * @param buff pointer to a location to store the peeked value
 *
 * @return circular buffer status code
 */
CB_Status_t CB_peek(CB_t* cb, uint32_t peekDepth, uint8_t* buff);



/**
 * @brief function to allocate memory for and initialize a circular buffer
 * 
 * This function takes a buffer and turns it into a circular buffer or reinitializes a 
 * given circular buffer.
 *
 * @param cb pointer to circular buffer
 * @param size number of items in the circular buffer 
 *
 * @return circular buffer status code
 */
CB_Status_t CB_init(CB_t* cb, uint32_t size);



/**
 * @brief function to free the memory that a given circular buffer is holding
 * 
 * This function frees the memory that a given circular buffer is holding and returns
 * a buffer status code based on what occurred during its execution. 
 *
 * @param cb pointer to circular buffer
 *
 * @return circular buffer status code
 */
CB_Status_t CB_destroy(CB_t* cb);
