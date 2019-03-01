## Problem description

Given some sequence of integers as combinations (no order), calculate the number of sequence which appearing the most time; if there are several sequence whose appearing times are the same, then the result is the sum of numbers of those sequences

## Algorithm analysis

Using a map to record the frequency of appeared combinations, and the combinations are stored as set and served as keys in the map.
The time complexity is O(nlogn).

## Knowledge base

1. Sometimes when you got a WA, maybe it is because we misunderstand the problem description. One way to avoid such situation is that once we got a WA, read the problem description once again and go over the sample test case again to make sure it is consistent with our implementation.
   After that, we can find the WA from other places.
2. You can use any object as the key in a C++ map as long as it defines "<" operator.