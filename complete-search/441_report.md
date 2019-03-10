## Problem description

Given 6 < k < 13 integers, enumerate all possible subsets of size 6 of these integers in sorted order.

## Algorithm analysis

Complete search solution:
Use 6 nested loops to enumerate all possible subsets of the integers.
The number of operations we would execute is at most $\binom{12}{6} = 924$, so it is solvable.

## Knowledge base

1. Lotto is the same as lottery. It chooses a subset of a set of integers as target.
   It is basically a combination problem in math.