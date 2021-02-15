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
