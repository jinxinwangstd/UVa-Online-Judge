## Problem description

Given an integer array A containing n < 20K non-zero integers, determine the maximum (1D) range sum of A. In other words, find the maximum Range Sum Query (RSQ) between two indices i and j in [0, ..., n-1], that is: A[i] + A[i+1] + A[i+2] + ... + A[j]

## Algorithm analysis

Dynamic programming solution (Greedy):
We define $\Phi(n)$ to be the maximum range sum in the range from 0th element to nth element.
Then we have such recurrence relation:
$\Phi(n) = max(\Phi(n-1), A[n])$                                  (If $\Phi(n-1)$ does not include A[n-1])
Or
$\Phi(n) = max(\Phi(n-1), A[n], \Phi(n-1) + A[n])$             (If $\Phi(n-1) includes A[n-1]$)
Thus here is the Kadane's algorithm:
Make a linear scan of the array while maintaining a sum of current sequence, which starts at an element the sum of whose former elements are negative. Every time we scan one more element, we update the sum and the maximum range sum accordingly.

## Knowledge base

1. Max 1D Range Sum:
   It is a classical kind of dynamic programming problem. With Kadane's algorithm, we can get the maximum range sum in O(n) time.
2. Visulization of Kadane's algorithm:
   We can view its algorithm as calculate the maximum Area Under Curve (AUC) where the curve is consist of infinite single line whose length is its area.
3. Pre-compute trick:
   When we always need sums of some continuous elements in an array, we can pre-compute the sum from 0th element to nth-element in the nth element in an new array A.
   If we do this, query of the sum of [i, j] only takes O(1) time because Sum[i, j] = A[j] - A[i-1] and Sum[0, j] = A[j].
4. If we need to output the range of the maximum range sum, we need two more variables: start and end.
   Start is the start element of the current sequence, which is updated every time when we get a negative sum.
   End is the end element of the current sequence, which is basically current scanning element.