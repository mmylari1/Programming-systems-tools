#include "functions.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <stdio.h>

/* Declarations of solution implementations */
int _next_multiple(int start, int factor);
float _ftoc(float fahrenheit);
int _fibonacci(unsigned int n);

/* The suite initialization function.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void) { return 0; }

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void) { return 0; }

/* Test of hello */
void testHELLO(void){
  hello("Hello world!\n");
  CU_PASS("Successfully called hello()");
}

/* Test of next_multiple */
void testNEXT_MULTIPLE(void) {
  int is[] = {0, 100, 365, 12258, 996};
  int js[] = {1, 10, 7, 28, 4};
  for (int idx = 0; idx <= 2; idx++) {
    CU_ASSERT_EQUAL(next_multiple(is[idx], js[idx]),
                    _next_multiple(is[idx], js[idx]))
  }
}

/* Test of ftoc */
void testFTOC(void) {
  float fahrenheits[] = {40, 32, 212, 0, -459.67};
  for (int idx = 0; idx <= 4; idx++) {
    CU_ASSERT_EQUAL(ftoc(fahrenheits[idx]), _ftoc(fahrenheits[idx]))
  }
}

/* Test of fibonacci */
void testFIBONACCI(void) {
  int ns[] = {0, 1, 2, 20, 40};
  for (int idx = 0; idx <= 4; idx++) {
    CU_ASSERT_EQUAL(fibonacci(ns[idx]), _fibonacci(ns[idx]))
  }
}

int main(int argc, char *argv[]) {
  CU_pSuite pSuite = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* add a suite to the registry */
  pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */
  if ((NULL == CU_add_test(pSuite, "test of hello", testHELLO)) ||
      (NULL ==
       CU_add_test(pSuite, "test of next_multiple", testNEXT_MULTIPLE)) ||
      (NULL == CU_add_test(pSuite, "test of ftoc", testFTOC)) ||
      (NULL == CU_add_test(pSuite, "test of fibonacci", testFIBONACCI))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}