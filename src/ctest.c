#include "../include/ctest.h"

static test_t **tests;
static int tests_k;

/**
 * Executes one test check. Fails if NULL passed
 * @param test Test to execute
 * @param failde_k Counter of failed tests. Link is passed because it is incremented inside function body
 * @param n Test number to print
 */
void execute_test(test_t *test, int *failed_k, int n)
{
  if (test == NULL)
  {
    fprintf(stderr, "No such test: %d", n + 1);
    exit(EXIT_FAILURE);
  }

  if (test->result)
    fprintf(stdout, "%s\n\033[0;32m%d - Passed\033[0m\n", test->name, n + 1);
  else
  {
    fprintf(stdout, "\033[0;31m%d FAILED\033[0m\n", n + 1);
    fprintf(stderr, "Test %d failded", n + 1);
    failed_k++;
  }
}

/**
 * Runs all tests
 * Execute after all test declarations.
 * @param which Array of numbers of tests to execute ending with -1 or NULL if all tests must be run.
 */
void run_tests(int *which)
{
  fprintf(stdout, "Executing tests:\n");

  int failed_k = 0;

  if (which == NULL)
  {
    for (int i = 0; i < tests_k; i++)
      execute_test(tests[i], &failed_k, i);
  }
  else
  {
    int i = 0;
    while (which[i] != -1)
    {
      int j = which[i];

      if (j < 0 || j >= tests_k)
      {
        fprintf(stderr, "No such test: %d", j + 1);
        exit(EXIT_FAILURE);
      }

      execute_test(tests[j], &failed_k, j);
      i++;
    }
  }

  if (failed_k > 0)
  {
    fprintf(stderr, "%d tests failed", failed_k);
    exit(EXIT_FAILURE);
  }
  else
  {
    fprintf(stdout, "All tests passed");
    exit(EXIT_SUCCESS);
  }
}

/**
 * Creates new test struct
 */
test_t *new_test(int res, char *name)
{
  test_t *n_t = (test_t *)malloc(sizeof(test_t));

  n_t->name = strdup(name);
  n_t->result = res;

  return n_t;
}

/**
 * Frees memory allocated for test structure
 */
void free_test(test_t *o_t)
{
  free(o_t->name);
  free(o_t);
}

/**
 * Test declarator. Adds specified test to list of tests
 * @param res Response of testing function
 * @param name Test name
 */
void test(int res, char *name)
{
  if (tests == NULL)
  {
    tests = malloc(0);
    tests_k = 0;
  }

  tests = realloc(tests, (tests_k + 1) * sizeof(test_t *));
  tests[tests_k] = new_test(res, name);
  tests_k++;
}