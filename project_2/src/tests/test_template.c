#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "template.h"

void test_equal(void **state)
{
  int val1 = 0;
  int val2 = functionToBeTested(arg);
  assert_int_equal(val1, val2);
}

void test_not_equal(void **state)
{
  int val1 = 0;
  int val2 = functionToBeTested(arg);
  assert_int_not_equal(val1, val2);
}

void test_true(void **state)
{
  int val1 = 0;
  int val2 = functionToBeTested(arg);
  assert_true(val1 < val2);
}

void test_skip(void **state)
{
  skip();
}

int main(int argc, char **argv)
{
  const struct CMUnitTest template_tests[] = 
  {
    cmocka_unit_test(test_equal),
    cmocka_unit_test(test__notequal),
    cmocka_unit_test(test_true),
    cmocka_unit_test(test_skip),
  };

  return cmocka_run_group_tests(template_tests, NULL, NULL);
}
