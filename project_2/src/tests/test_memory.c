#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdlib.h>

#include "memory.h"

uint8_t* ptr;
uint8_t* cnst;
uint8_t* nullPtr;
const int bg = 42;


void init_tests()
{
	ptr = malloc(10);
	cnst = malloc(10);
}

void setup_tests()
{
	int i;
	for(i = 0; i < 10; i++)
	{
		*(ptr + i) = bg;
		*(cnst + i) = i;
	}
	
	nullPtr = ((uint8_t*) 0);
}

void test_memmove_null_ptr1(void **state)
{
	setup_tests();

	uint8_t * result = my_memmove(nullPtr, ptr, 2);

	assert_null(result);
}

void test_memmove_null_ptr2(void **state)
{
	setup_tests();

	uint8_t* result = my_memmove(ptr, nullPtr, 2);

	assert_null(result);
}


void test_memmove_no_overlap(void **state)
{
	setup_tests();
	uint8_t* ptr1 = ptr;
	uint8_t* ptr2 = (ptr + 5);
	
	int i;
	for(i = 0; i < 4; i++)
	{
		*(ptr1 + i) = *(cnst + i);
	}

	uint8_t* result = my_memmove(ptr1, ptr2, 4);

	assert_memory_equal(cnst, ptr2, 4);
}

void test_memmove_overlap1(void **state)
{
	setup_tests();
	uint8_t* ptr1 = ptr;
	uint8_t* ptr2 = (ptr + 2);
	
	int i;
	for(i = 0; i < 4; i++)
	{
		*(ptr1 + i) = *(cnst + i);
	}

	uint8_t* result = my_memmove(ptr1, ptr2, 4);

	assert_memory_equal(cnst, ptr2, 4);
}

void test_memmove_overlap2(void **state)
{
	setup_tests();
	uint8_t* ptr1 = (ptr + 1);
	uint8_t* ptr2 = ptr;
	
	int i;
	for(i = 0; i < 4; i++)
	{
		*(ptr1 + i) = *(cnst + i);
	}

	uint8_t* result = my_memmove(ptr1, ptr2, 4);

	assert_memory_equal(cnst, ptr2, 4);
}

void test_memmove_overlap3(void **state)
{
	setup_tests();
	uint8_t* ptr1 = (ptr + 1);
	uint8_t* ptr2 = ptr1;
	
	int i;
	for(i = 0; i < 4; i++)
	{
		*(ptr1 + i) = i;
	}

	uint8_t* result = my_memmove(ptr1, ptr2, 4);

	assert_memory_equal(cnst, ptr2, 4);
}

void test_memcopy_null_ptr1(void **state)
{
	setup_tests();

	uint8_t * result = my_memcopy(nullPtr, ptr, 2);

	assert_null(result);
}

void test_memcopy_null_ptr2(void **state)
{
	setup_tests();

	uint8_t* result = my_memcopy(ptr, nullPtr, 2);

	assert_null(result);
}


void test_memcopy_no_overlap(void **state)
{
	setup_tests();
	uint8_t* ptr1 = ptr;
	uint8_t* ptr2 = (ptr + 5);
	
	int i;
	for(i = 0; i < 4; i++)
	{
		*(ptr1 + i) = *(cnst + i);
	}

	uint8_t* result = my_memcopy(ptr1, ptr2, 4);

	assert_memory_equal(cnst, ptr2, 4);
}

void test_memcopy_overlap1(void **state)
{
	setup_tests();
	uint8_t* ptr1 = ptr;
	uint8_t* ptr2 = (ptr + 2);
	
	int i;
	for(i = 0; i < 4; i++)
	{
		*(ptr1 + i) = *(cnst + i);
	}

	uint8_t* result = my_memcopy(ptr1, ptr2, 4);

	assert_memory_equal(cnst, ptr2, 4);
}

void test_memcopy_overlap2(void **state)
{
	setup_tests();
	uint8_t* ptr1 = (ptr + 1);
	uint8_t* ptr2 = ptr;
	
	int i;
	for(i = 0; i < 4; i++)
	{
		*(ptr1 + i) = *(cnst + i);
	}

	uint8_t* result = my_memcopy(ptr1, ptr2, 4);

	assert_memory_equal(cnst, ptr2, 4);
}

void test_memcopy_overlap3(void **state)
{
	setup_tests();
	uint8_t* ptr1 = (ptr + 1);
	uint8_t* ptr2 = ptr1;
	
	int i;
	for(i = 0; i < 4; i++)
	{
		*(ptr1 + i) = i;
	}

	uint8_t* result = my_memcopy(ptr1, ptr2, 4);

	assert_memory_equal(cnst, ptr2, 4);
}

void test_memset_null_ptr(void **state)
{
	setup_tests();

	uint8_t * result = my_memset(nullPtr, 2, 2);

	assert_null(result);
}

void test_memset_success(void **state)
{
	setup_tests();
	uint8_t* ptr1 = (ptr + 1);
	int len = 4;
	int val = 1;

	uint8_t* result = my_memcopy(ptr1, len, val);


	int i;
	for(i = 0; i < len; i++)
	{
		assert_int_equal(*(ptr1 + i), val);
	}
	assert_int_equal(*(ptr1 - 1), bg);
	assert_int_equal(*(ptr1 + len), bg);
}

void test_memzero_null_ptr(void **state)
{
	setup_tests();

	uint8_t * result = my_memzero(nullPtr, 2);

	assert_null(result);
}

void test_memzero_success(void **state)
{
	setup_tests();
	uint8_t* ptr1 = (ptr + 1);
	int len = 4;
	int val = 0;

	uint8_t* result = my_memzero(ptr1, len);


	int i;
	for(i = 0; i < len; i++)
	{
		assert_int_equal(*(ptr1 + i), val);
	}
	assert_int_equal(*(ptr1 - 1), bg);
	assert_int_equal(*(ptr1 + len), bg);
}

int main(int argc, char **argv)
{
	init_tests();
  	const struct CMUnitTest memory_tests[] = 
  	{
    	cmocka_unit_test(test_memmove_null_ptr1),
    	cmocka_unit_test(test_memmove_null_ptr2),
    	cmocka_unit_test(test_memmove_no_overlap),
    	cmocka_unit_test(test_memmove_overlap1),
    	cmocka_unit_test(test_memmove_overlap2),
    	cmocka_unit_test(test_memmove_overlap3),

    	cmocka_unit_test(test_memcopy_null_ptr1),
    	cmocka_unit_test(test_memcopy_null_ptr2),
    	cmocka_unit_test(test_memcopy_no_overlap),
    	cmocka_unit_test(test_memcopy_overlap1),
    	cmocka_unit_test(test_memcopy_overlap2),
    	cmocka_unit_test(test_memcopy_overlap3),

    	cmocka_unit_test(test_memset_null_ptr),
    	cmocka_unit_test(test_memset_success),

    	cmocka_unit_test(test_memzero_null_ptr),
    	cmocka_unit_test(test_memzero_success),

    	cmocka_unit_test(test_memcopy_overlap3),
  	};

  	free(ptr);
  	free(cnst);

  	return cmocka_run_group_tests(memory_tests, NULL, NULL);
}