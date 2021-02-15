#ifndef CTEST_H
#define CTEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test_structure
{
  int result;
  char *name;
} test_t;

void run_tests(int *which);
test_t *new_test(int res, char *name);
void free_test(test_t *o_t);
void test(int res, char *name);

#endif