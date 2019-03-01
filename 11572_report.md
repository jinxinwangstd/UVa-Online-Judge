## Problem description

Longest Non-repeated Sequence of integer

## Algorithm analysis

Sliding window method:
The whole process is a linear scan of the integer sequence. We try to build a non-repeated sequence from the start. Every time we met a repeated integer, the length of the current non-repeated sequence is determined, and next non-repeated sequence starts from one past the last occurrence of this repeated integer.
With this method, we need to record the latest occurrence of each integer. We don't care the other former occurrence because to check collision with elements in our current non-repeated sequence, all those elements are latest. We use BST instead of DAT or hash table because the range of possibly appeared integer is large (1 million).
One corner case is that we only determine the length of the current non-repeated sequence when we met a repeated element. However, for the last non-repeated sequence (ended with the last character), we may have no chance to determine its length during the linear scan. So we need to add a check after the linear scan to cover the last possible non-repeated sequence.

## Knowledge base

1. When the test case is a sequence or set with different size, make sure we test the test cases with the smallest size and largest size.
   For example, in this problem the corner case would appear with the test case of size 1, but I overlooked it. This should be reminded every time after implementing the algorithm.