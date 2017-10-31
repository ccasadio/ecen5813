#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "cbuff.h"
#include <stdlib.h>
#include <stdio.h>

#define SIZE (5)

static int group_setup(void **state)
{
    CB_t *cb = malloc(sizeof(CB_t));
    assert_non_null(cb);
    CB_init(cb, SIZE);
    *state = cb;
    return 0;
}

static int group_teardown(void **state)
{
    CB_t *cb = (CB_t*)*state;
    CB_destroy(cb);
    free((void*)cb);
    return 0;
}

void test_cb_add_null(void **state)
{
    CB_t* cb = NULL;

    uint8_t a = 6;
    CB_Status_t outcome = CB_buffer_add_item(cb, &a);

    assert_int_equal(outcome, NullPointer);
}

void test_cb_remove_null(void **state)
{
    CB_t* cb = NULL;

    uint8_t b = 4;
    CB_Status_t outcome = CB_buffer_remove_item(cb, &b);

    assert_int_equal(outcome, NullPointer);
}

void test_cb_is_full_null(void **state)
{
    CB_t* cb = NULL;

    CB_Status_t outcome = CB_is_full(cb);

    assert_int_equal(outcome, NullPointer);
}

void test_cb_is_empty_null(void **state)
{
    CB_t* cb = NULL;

    CB_Status_t outcome = CB_is_empty(cb);

    assert_int_equal(outcome, NullPointer);
}

void test_cb_peek_null(void **state)
{
    CB_t* cb = NULL;

    size_t a = 4;
    uint8_t b = 3;
    CB_Status_t outcome = CB_peek(cb, a, &b);

    assert_int_equal(outcome, NullPointer);
}

void test_cb_init_null(void **state)
{
    CB_t* cb = NULL;

    size_t a = 4;
    CB_Status_t outcome = CB_init(cb, a);

    assert_int_equal(outcome, NullPointer);
}

void test_cb_destroy_null(void **state)
{
    CB_t* cb = NULL;

    CB_Status_t outcome = CB_destroy(cb);

    assert_int_equal(outcome, NullPointer);
}

void test_cb_add_uninit(void **state)
{
    CB_t *cb = malloc(sizeof(CB_t));

    uint8_t a = 6;
    CB_Status_t outcome = CB_buffer_add_item(cb, &a);

    assert_int_equal(outcome, NotInit);
}

void test_cb_remove_uninit(void **state)
{
    CB_t *cb = malloc(sizeof(CB_t));

    uint8_t b = 4;
    CB_Status_t outcome = CB_buffer_remove_item(cb, &b);

    assert_int_equal(outcome, NotInit);
}

void test_cb_is_full_uninit(void **state)
{
    CB_t *cb = malloc(sizeof(CB_t));

    CB_Status_t outcome = CB_is_full(cb);

    assert_int_equal(outcome, NotInit);
}

void test_cb_is_empty_uninit(void **state)
{
    CB_t *cb = malloc(sizeof(CB_t));

    CB_Status_t outcome = CB_is_empty(cb);

    assert_int_equal(outcome, NotInit);
}

void test_cb_peek_uninit(void **state)
{
    CB_t *cb = malloc(sizeof(CB_t));

    size_t a = 4;
    uint8_t b = 3;
    CB_Status_t outcome = CB_peek(cb, a, &b);

    assert_int_equal(outcome, NotInit);
}

void test_cb_init_uninit(void **state)
{
    CB_t *cb = malloc(sizeof(CB_t));

    size_t a = 4;
    CB_Status_t outcome = CB_init(cb, a);

    assert_int_equal(outcome, Success);
}

void test_cb_destroy_uninit(void **state)
{
    CB_t *cb = malloc(sizeof(CB_t));

    CB_Status_t outcome = CB_destroy(cb);

    assert_int_equal(outcome, NotInit);
}

void test_cb_add_remove(void **state)
{
    CB_t* cb = ((CB_t*)*state);

    uint8_t a = 42;
    uint8_t b = 0;

    CB_Status_t outcome = CB_buffer_add_item(cb, &a);
    assert_int_equal(outcome, Success);

    outcome = CB_buffer_remove_item(cb, &b);
    assert_int_equal(outcome, Success);

    assert_int_equal(a, b);
}

void test_cb_add_full(void **state)
{
    CB_t* cb = ((CB_t*)*state);

    uint8_t a = 42;
    uint8_t i;

    CB_Status_t outcome;

    for(i = 0; i < SIZE; i++)
    {
        outcome = CB_buffer_add_item(cb, &a);
        assert_int_equal(outcome, Success);
    }

    outcome = CB_buffer_add_item(cb, &a);
    assert_int_equal(outcome, BufferFull);
}

void test_cb_is_full(void **state)
{
    CB_t* cb = ((CB_t*)*state);

    uint8_t a = 42;
    uint8_t i;

    for(i = 0; i < SIZE + 1; i++)
    {
        CB_buffer_add_item(cb, &a);
    }

    assert_true(CB_is_full(cb));
}

void test_cb_add_remove_wrap1(void **state)
{
    CB_t* cb = ((CB_t*)*state);

    CB_init(cb, SIZE);

    uint8_t a = 0;
    uint8_t b = 0;
    uint8_t i;
    CB_Status_t outcome;

    for(i = 0; i < SIZE * 3; i++)
    {
        a = i;

        outcome = CB_buffer_add_item(cb, &a);
        assert_int_equal(outcome, Success);
        
        outcome = CB_buffer_remove_item(cb, &b);
        assert_int_equal(outcome, Success);
        
        assert_int_equal(a, b);
    }
}

void test_cb_add_remove_wrap2(void **state)
{
    CB_t* cb = ((CB_t*)*state);

    uint8_t a = 0;
    uint8_t b = 0;
    uint8_t i;

    CB_Status_t outcome = CB_buffer_add_item(cb, &a);
    assert_int_equal(outcome, Success);

    for(i = 1; i < SIZE * 3; i++)
    {
        a = i;

        outcome = CB_buffer_add_item(cb, &a);
        assert_int_equal(outcome, Success);

        outcome = CB_buffer_remove_item(cb, &b);
        assert_int_equal(outcome, Success);

        assert_int_equal(a - 1, b);
    }
}

void test_cb_remove_empty1(void **state)
{
    CB_t* cb = ((CB_t*)*state);

    CB_init(cb, SIZE);

    uint8_t a = 0;

    CB_Status_t outcome = CB_buffer_remove_item(cb, &a);
    assert_int_equal(outcome, BufferEmpty);
}

void test_cb_remove_empty2(void **state)
{
    CB_t* cb = ((CB_t*)*state);

    uint8_t a = 0;

    CB_Status_t outcome = CB_buffer_add_item(cb, &a);
    assert_int_equal(outcome, Success);

    outcome = CB_buffer_remove_item(cb, &a);
    assert_int_equal(outcome, Success);

    outcome = CB_buffer_remove_item(cb, &a);
    assert_int_equal(outcome, BufferEmpty);
}


int main(int argc, char **argv)
{
    const struct CMUnitTest cbuff_tests[] = 
    {
        cmocka_unit_test(test_cb_add_null),
        cmocka_unit_test(test_cb_remove_null),
        cmocka_unit_test(test_cb_is_full_null),
        cmocka_unit_test(test_cb_is_empty_null),
        cmocka_unit_test(test_cb_peek_null),
        cmocka_unit_test(test_cb_init_null),
        cmocka_unit_test(test_cb_destroy_null),
        cmocka_unit_test(test_cb_add_uninit),
        cmocka_unit_test(test_cb_remove_uninit),
        cmocka_unit_test(test_cb_is_full_uninit),
        cmocka_unit_test(test_cb_is_empty_uninit),
        cmocka_unit_test(test_cb_peek_uninit),
        cmocka_unit_test(test_cb_init_uninit),
        cmocka_unit_test(test_cb_destroy_uninit),
        cmocka_unit_test(test_cb_add_remove),
        cmocka_unit_test(test_cb_add_full),
        cmocka_unit_test(test_cb_is_full),
        cmocka_unit_test(test_cb_add_remove_wrap1),
        cmocka_unit_test(test_cb_add_remove_wrap2),
        cmocka_unit_test(test_cb_remove_empty1),
        cmocka_unit_test(test_cb_remove_empty2),
    };

    return cmocka_run_group_tests(cbuff_tests, group_setup, group_teardown);
}