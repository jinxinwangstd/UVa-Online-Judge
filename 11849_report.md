## Problem description

Given two ascending sequence of integers (non-repeated), determine the number of same elements in two sequences.

## Algorithm analysis

Use set container to store one sequence, then linear scan the other sequence, compared with each element in the first sequence, finally get the result.

## Knowledge base

1. "jn" is the name of a function in <math.h>

   ```c++
   double jn(int, double);
   ```

2. The compiler error message "symbol_name redeclared as different kind of symbol" means that you have a name collision in your current scope, that is you define two symbol with same name but different types.