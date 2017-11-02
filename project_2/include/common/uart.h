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
* @file uart.h
* @brief 
*
* 
* 
*
* @author Christian Casadio
* @date Oct. 22, 2017
* @version 1.0
*
*/

#include <stdlib.h>
#include <stdint.h>

typedef enum
{
	Success = 0;
	NullPointer;
	NoLength;
} UART_Status_t;

/**
 * @brief function to configure UART to the given settings
 * 
 * This function configures UART to the given settings 
 *
 * @return 
 */
UART_Status_t UART_configure(uint16_t baud);


/**
 * @brief function to send a single byte down a specific UART device
 *
 * @param data data to be sent
 *
 * @return 
 */
UART_Status_t UART_send (unint8_t* data);


/**
 * @brief function to send multiple bytes down a specific UART device 
 *
 * @param data data to be sent
 * @param length number of bytes of data
 *
 * @return
 */
UART_Status_t UART_send_n (unint8_t* data, size_t length);


 /**
 * @brief function to return a received byte on the UART using an input parameter pointer
 *
 * @param buffer place to store received data 
 *
 * @return 
 */
 UART_Status_t UART_receive(unint8_t* buffer);


 /**
 * @brief function to receive a number of bytes on the UART
 *
 * @param buffer place to store received data
 * @param length number of bytes of data
 *
 * @return
 */
 UART_Status_t UART_receive_n (unint8_t* buffer, size_t length);