## Problem description

Given three integers A, B, and C (1 <= A, B, C <= 10000), find three other distinct integers x, y, and z such that x + y + z = A, x * y * z = B, and x^2 + y^2 + z^2 = C.

## Algorithm analysis

Complete search solution:
Through analysis, the possible range of A, B, C is [-sqrt(C), sqrt(C)], which at most is [-100, 100]. So the number of possible combinations of A, B, and C is 200 * 200 * 200 = 8000000. Thus, we can enumerate all possible combinations and check whether it satisfies the formulas.
The number of total operations we would execute is at most 8M * (a (additions) + b (multiplications) + c (additions and multiplications)), so it is solvable.

## Knowledge base

1. To use a complete search method to solve a problem, we should think all methods to prune the search space.
   First, utilize the parameters the problem gives. For example, in this problem, the parameter C tells us the possible range of x, y, and z is [-sqrt(C), sqrt(C)]; the parameter B tells us the maximum value of x is $\sqrt[3]{B}$. Such techniques can speed up our search process.
   Second, utilize the characteristics of your search space, like alpha-beta pruning.