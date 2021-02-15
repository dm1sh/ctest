# Testing library for C

Mostly specialized on unit tests library for improved testing experience

# Example:

```c
#include "ctest.h"
#include "funcs.h"
...
test(is_true(some_function()), "Function is true");
run_tests();
...

```

# Currently builtin matchers

You can use the following functions or just pass boolean value as first argument of `test()`

* `int is_equal(void *res, void *correct);`
* `int is_true(void *res);`
* `int is_false(void *res);`

# Installation:

```bash
make clean
make CT_VERSION=1
sudo make install CT_VERSION=1
```

# Uninstall:

It is also required for update

```bash
sudo make uninstall  CT_VERSION=1
```
