

#include "cbuff.h"

CB_Status_t check_CB(CB_t* cb)
{
	if(!cb)
	{
		return NullPointer;
	}

	if(!(cb->bufferStart))
	{
		return NotInit;
	}

	if(!(cb->bufferEnd))
	{
		return NotInit;
	}

	if(!(cb->head))
	{
		return NotInit;
	}

	if(!(cb->tail))
	{
		return NotInit;
	}

	if(cb->dataCapacity < 2)
	{
		return NotInit;
	}

	return Success;
}

CB_Status_t CB_buffer_add_item(CB_t* cb, uint8_t* data)
{
	if(check_CB(cb))
	{
		return check_CB(cb);
	}

	if(CB_is_full(cb))
	{
		return BufferFull;
	}

	*(cb->head) = *data;
	cb->head ++;

	if(cb->head == cb->bufferEnd)
	{
		cb->head = cb->bufferStart;
	}

	cb->dataNum++;

	return Success;
}


CB_Status_t CB_buffer_remove_item(CB_t* cb, uint8_t* buff)
{
	if(check_CB(cb))
	{
		return check_CB(cb);
	}

	if(CB_is_empty(cb))
	{
		return BufferEmpty;
	}

	*buff = *(cb->tail);
	cb->tail ++;

	if(cb->tail == cb->bufferEnd)
	{
		cb->tail = cb->bufferStart;
	}

	cb->dataNum--;

	return Success;
}


CB_Status_t CB_is_full(CB_t* cb)
{
	if(check_CB(cb))
	{
		return check_CB(cb);
	}

	if(cb->dataNum == cb->dataCapacity)
	{
		return BufferFull;
	}

	return Success;
}


CB_Status_t CB_is_empty(CB_t* cb)
{
	if(check_CB(cb))
	{
		return check_CB(cb);
	}

	if(cb->dataNum == 0)
	{
		return BufferEmpty;
	}

	return Success;
}


CB_Status_t CB_peek(CB_t* cb, size_t peekDepth, uint8_t* buff)
{
	if(check_CB(cb))
	{
		return check_CB(cb);
	}

	if(peekDepth > cb->dataNum)
	{
		return TooFewElements;
	}

	if(CB_is_empty(cb))
	{
		return BufferEmpty;
	}

	*buff = *((cb->tail) + peekDepth);

	return Success;
}


CB_Status_t CB_init(CB_t* cb, size_t size)
{
	if(!cb)
	{
		return NullPointer;
	}

	if(size < 2)
	{
		return NoLength;
	}


	cb->bufferStart = (uint8_t*)malloc(sizeof(uint8_t) * size);

	if(!(cb->bufferStart))
	{
		return BufferAllocationFailure;
	}

	cb->bufferEnd = ((uint8_t*)(cb->bufferStart) + (sizeof(uint8_t) * size));
	cb->head = cb->bufferStart;
	cb->tail = cb->bufferStart;
	cb->dataNum = 0;
	cb->dataCapacity = size;

	return Success;
}


CB_Status_t CB_destroy(CB_t* cb)
{
	if(check_CB(cb))
	{
		return check_CB(cb);
	}

	free(cb->bufferStart);

	return Success;
}