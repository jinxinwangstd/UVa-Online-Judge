## Problem description

Given a list l containing 1 <= n <= 20 integers, is there a subset of l that sums to another given integer X?

## Algorithm analysis

Complete search solution:
We enumerate all subsets of the given set, and check whether the sum of the subset is equal to the given integer X. The number of subsets of a set of size n is 2^n, so the maximum number of operations we would do is 2^20 * 20 = 20M. With the technique of bit manipulations, we can do it in 1 second.

## Knowledge base

1. To enumerate all subsets of a given set of size n, we can use the technique of bit manipulations:

   ```c++
   vector<vector<int> > subsets;
   for (int i = 0; i < (1 << n); ++i) {
       vector<int> subset;
       for (int j = 0; j < n; ++j) {
           if (i & (1 << j))
           	subset.push_back(s[j]);
       }
       subsets.push_back(subset);
   }
   ```

   