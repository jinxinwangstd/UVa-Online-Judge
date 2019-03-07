## Problem description

Find and display all pairs of 5-digit numbers that collectively use the digits 0 through 9 once each, such that the first number divided by the second is equal to an integer N, where 2 <= N <= 79. That is, abcde / fghij = N, where each letter represents a different digit.

## Algorithm analysis

Complete search solution:
Through analysis, we can find that fghij must fall into the range of [1234, 98765 / N], so we enumerate all possible values of fghij and calculate the corresponding abcde, then check whether they used every digit from 0 through 9.
The number of total operations we would execute is at most 50K * 10 = 500K, so it can be solved within one second. 

## Knowledge base

1. For a complete search solution, we need to quickly find the minimum range of possible values for the related variables in the problem.
   For example, in this problem the original range of fghij is [1234, 98765]. With considering the given value of N, we can shrink the range into [1234, 98765 / N].

2. To check whether a set of size N of integers have covered all digits or numbers from 0 through N-1, we can use the bit manipulation method:
   Starting from an bitmask 0, scan each integer x in the set and use the bit manipulation to set the xth bit in the bitmask. If the set covers from 0 through N-1, after setting all the corresponding bits, the bitmask would be equal to 2^N-1 (0b1111...1111). The example code is like:

   ```c++
   int used = 0;
   for (int i = 0; i != N; ++i)
       used |= (1 << x[i]);
   return used == (1 << N) - 1;
   ```

   

