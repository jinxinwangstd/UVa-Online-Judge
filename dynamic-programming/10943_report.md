## Problem description

Given an integer n, how many ways can K non-negative integers less than or equal to n add up to n? Constraints: $1 \leq n, K \leq 100$

## Algorithm analysis

Define $\Phi(n)$ to be the number of ways to add up to n. Then there is a recurrence relation which is
$\Phi(n, k) = \Sigma_{0} \Phi(n - x, k - 1)$
because we can view the number n as two parts, the first part is x as the first adding number, the rest is n-x, which we need to determine the ways to add up to.
There are n * k distinct states and each state need O(n) to calculate, so the overall time complexity is $O(n^2 \times k)$.

## Knowledge base

1. When we use dynamic programming, we need to represent the state so that there are many repeated sub-state when we try to calculate a state.
   For example, in this problem, there are two ways to represent the state addWays(rem, num):
   One way is that addWays(rem, num) should be the number of ways to add up to "rem" given we have used "num" integers.
   The other way is the addWays(rem, num) should be the number of ways to add up to "rem" using "num" integers.
   Obviously the second way is the correct way and there are many repeated sub-states compared to the first defining way.