## Problem description

Given an $n \times n$ (1 <= n <= 100) square matrix of integers A where each integer ranges from [-127, 127], find a sub-matrix of A with the maximum sum.

## Algorithm analysis

Dynamic programming (complete search) solution:
Pre-compute the sum of sub-matrix from (0, 0) to (i, j) and store the result in the (i, j) element of a same size matrix.
Then just go through every possible sub-matrix and compute their sum, and finally got the maximum one.
We can compute the sum of a sub-matrix in O(1) time and there are O(n^4) sub-matrix, so the overall time complexity is O(n^4).

## Knowledge base

1. Using a four-level looping we can enumerate all possible sub-matrix in a $n \times n$ matrix. There are O(n^4) sub-matrix.
2. When we frequently access some sum values over and over again, we usually choose to pre-compute them because computing sum takes O(n) time and pre-compute can eliminate it to O(1).
3. When we compute a sum of a sub-matrix, be careful about the double counting of the upper-left part.