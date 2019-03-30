## Problem description

Given a stick of length $1 \leq l \leq 1000$ and $1 \leq n \leq 50$ cuts to be made to the stick (the cut coordinates, lying in the range [0, ..., l], are given). The cost of a cut is determined by the length of the stick to be cut. Your task is to find a cutting sequence so that the overall cost is minimized.

## Algorithm analysis

To represent a state, we need to store the cutting points in an array, and then use the id of cutting points $l$ and $r$ to represent the stick we need to cut.
Define $\Phi(l, r)$ as the minimum cost of cutting stick starting from the l-th cutting point to the r-th cutting point. Then we have such recurrence relation as
$\Phi(l, r) = min(\Phi(l, n) + \Phi(n, r) + (r - l))    \forall n \in  (l ,r)$
As we can see, there are many duplicate sub-states, so we can use dynamic programming algorithm to solve it.
There are O(n^2) distinct states, and each state needs O(n) to calculate, so the overall time complexity is O(n^3)

## Knowledge base

1. When we need a very large integer value, we can use the macro INT_MAX defined in the C library \<limits.h>.
   Similarly, when we need a very small integer value, we can use the macro INT_MIN defined in the C library \<limits.h>.