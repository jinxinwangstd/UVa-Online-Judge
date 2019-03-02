## Problem description

 Given an empty group of integers (possible for duplicates), every time adding some integers to this group, and then extract the maximum and minimum elements in the group, calculate the absolute difference and accumulate them to get the final result

## Algorithm analysis

Simulate the whole process with a multiset storing the elements in the group.

## Knowledge base

1. Every time when we confront with calculations like accumulation, multiplication, we must be aware of the risk of integer overflow. We must be sensitive to the possible range of integer result.
   For example in this problem the result could be 10^6 * (10^5 / 2), which is too large for an int object.

2. For a multiset container, we can not directly get the maximum element and minimum element, but we can get their corresponding iterators.
   For example, for a ascending multiset of integers:

   ```c++
   multiset<int>::iterator max_iter = --m.end();
   multiset<int>::iterator min_iter = m.begin();
   ```

3. We can only erase an element in a multiset container which is pointed by a regular iterators. Other iterators like reverse iterators are not eligible.