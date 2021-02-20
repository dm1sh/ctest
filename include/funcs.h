#ifndef FUNCS_H
#define FUNCS_H

int is_equal(void *res, void *correct);
int is_true(void *res);
int is_false(void *res);
int is_equal_array(void **res, int size, void **correct);
int not(void *res);

#endif