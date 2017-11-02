

#include "uart.h"
#include "MKL25Z4.h"
#include "system_MKL25Z4.h"


//to be moved to function argument in future version to support all available uarts
static UART_Type* base = UART0;

UART_Status_t UART_configure (uint16_t baud)
{
	uint16_t prescaler;

	//reset uart registers according to KL25 Sub-Family Reference Manual p. 724-5
    UART_BDH_REG(base) = (0x00U);
    UART_BDL_REG(base) = (0x04U);
    UART_C1_REG(base)  = (0x00U);
    UART_C2_REG(base)  = (0x00U);
    UART_S1_REG(base)  = (0xC0U);
    UART_S2_REG(base)  = (0x00U);
    UART_C3_REG(base)  = (0x00U);
	UART_D_REG(base)   = (0x00U);
	UART_C4_REG(base)  = (0x00U);
    //UART_MA1_REG(base) = (0x00U);
    //UART_MA2_REG(base) = (0x00U);
	//UART_C5_REG(base) = (0x00U);

	//use sim to route clock to UART0 and PORTA
	SIM_SCGC4_REG(base) |= SIM_SCGC4_UART0_MASK;
	SIM_SCGC5_REG(base) |= SIM_SCGC5_PORTA_MASK;
	SIM_SOPT2_REG(base) |= SIM_SOPT2_UART0SRC(1);

	//set pinout according to Kinetis KL25 Sub-Family user guide p. 45
	PORTA_PCR1 |= PORT_PCR_MUX(2);
	PORTA_PCR2 |= PORT_PCR_MUX(2);

	prescaler = ((DEFAULT_SYSTEM_CLOCK * 8U / 10U)/baud);	//prescaler = (clock * symbols/bits)/baud
	UART_BDH_REG(base) |= prescaler >> 8;
	UART_BDL_REG(base) |= prescaler;

 
 	UART_C2_REG(base) = (UART_C2_TE_MASK|UART_C2_RE_MASK|UART_C2_RIE_MASK);
}


UART_Status_t UART_send(unint8_t* data)
{
	if(!data)
	{
		return NullPointer;
	}

	while(!(UART_S1_REG(base) & UART_S1_TDRE_MASK));

	UART_D_REG(base) = data;
	
	while(!(UART_S1_REG(base) & UART_S1_TC_MASK));
}

UART_Status_t UART_send_n(unint8_t* data, size_t length)
{
	UART_Status_t status;

	while(length--)	
	{
		status = UART_send(data++);

		if(status)
		{
			return status;
		}
	}

	return status;
}

UART_Status_t UART_receive(unint8_t* buffer)
{
	if(!buffer)
	{
		return NullPointer;
	}

	while(!(UART_S1_RDRF( UART_S1_REG(base) )))
	
	*buffer = UART0_D;
	
	return Success;
}

UART_Status_t UART_receive_n(unint8_t* buffer, size_t length)
{
	UART_Status_t status;

	while(length--)	
	{
		status = UART_send(data++);

		if(status)
		{
			return status;
		}
	}

	return status;
}

void UART0_IRQHandler(void)
{
	uint8_t status = UART_S1_REG(UART0);
	UART_S1_REG(UART0) &= ~(status);

	//list of if cases for each status case
}