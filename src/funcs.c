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

int is_equal_array(void **res, int size, void **correct)
{
  for (int i = 0; i < size; i++)
    if (res[i])
      if (res[i] != correct[i])
        return 0;

  return 1;
}

int not(void *res)
{
  return !res;
}