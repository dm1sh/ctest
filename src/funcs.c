#include "../include/funcs.h"

int is_equal(void *res, void *correct)
{
  return res == correct;
}

int is_true(void *res)
{
  return res && 1;
}

int is_false(void *res)
{
  return !res;
}