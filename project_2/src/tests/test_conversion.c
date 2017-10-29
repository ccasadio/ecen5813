#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "conversion.h"
#include <stdlib.h>
#include <stdint.h>

#define NUM 1

static int group_setup(void **state)
{
    uint32_t *answer = malloc(sizeof(uint32_t));
    assert_non_null(answer);
    *answer = NUM;
    *state = answer;
    return 0;
}

static int group_teardown(void **state)
{
    int *answer = (int *)*state;
    free(answer);
    return 0;
}

void test_big_to_little(void **state)
{
    uint32_t* a = ((uint32_t *)*state);
    *a = NUM;

    uint8_t success = big_to_little32(a, 1);

    assert_int_equal(success, 0);
    assert_int_equal(a, NUM << (4 * sizeof(a)));
}

void test_little_to_big(void **state)
{
    uint32_t* a = ((uint32_t *)*state);
    *a = NUM;

    uint8_t success = little_to_big32(a, 1);

    assert_int_equal(success, 0);
    assert_int_equal(a, NUM << (4 * sizeof(a)));
}

void test_big_to_little_null(void **state)
{
    uint32_t* a = NULL;
    uint8_t success = big_to_little32(a, 1);

    assert_int_not_equal(success, 0);
    assert_int_equal(a, NUM);
}

void test_little_to_big_null(void **state)
{
    uint32_t* a = NULL;
    uint8_t success = little_to_big32(a, 1);

    assert_int_not_equal(success, 0);
    assert_int_equal(a, NUM);
}

int main(int argc, char **argv)
{
    const struct CMUnitTest template_tests[] = 
    {
        cmocka_unit_test(test_big_to_little),
        cmocka_unit_test(test_big_to_little_null),
        cmocka_unit_test(test_little_to_big),
        cmocka_unit_test(test_little_to_big_null),
    };

    return cmocka_run_group_tests(template_tests, group_setup, group_teardown);
}
