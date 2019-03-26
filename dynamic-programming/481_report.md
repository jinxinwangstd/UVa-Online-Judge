## Problem description

Given a sequence of integers, select the longest strictly increasing subsequence of integers from it.

## Algorithm analysis

Greedy + Divide&Conquer Solution:
We maintain a sorted array L where L(i) represents the smallest ending value of all LIS of length i found so far when we perform a linear scan of the original list.
To maintain such an array, every time we scan a new element, we use binary search to find this element's position in L. If this element is greater than all elements in L, we just append it to L; otherwise we replace the smallest element which is greater than it with this new element.
In the end, the length of L is the length of LIS in the original list. We can prove this by mathematical induction. The L of length 1 is valid LIS, and every time we append a new element, there must be a valid LIS with same length because the new element is greater than all elements appeared in L.
However, L may not be the LIS itself. To reconstruct the LIS, every time we insert or append a new element in L, we need to record its predecessor's id (index in the original list). In such way, we form a linked list with every element appeared in L pointing to its predecessor. With the id of the last element, we can reconstruct the LIS by backtracking with a stack. P.S. this LIS is the last appeared LIS if there is a tie.
If the length of LIS is k, the overall time complexity is O(nlogk) where n is the number of elements in the original list.

## Knowledge base

1. Binary search related functions in C++ algorithm library:

   ```c++
   ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val);
   ```

   The lower_bound() returns an iterator pointing to the first element in range [first, last) which is equal to or greater than val.

   ```c++
   ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val);
   ```

   The upper_bound() returns an iterator pointing to the first element in range [first, last) which is greater than val.
   The prerequisite of returning correct result is the range of [first, last) is sorted.
   The algorithm use '<' operator to get the result. We can pass our own compare function.

   ```c++
   ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
   ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
   ```

   If the range is sorted in descending order and we pass a greater function, the lower_bound() would return the first element which is less than or equal to val.

2. In the greedy + divide&conquer solution of LIS, we need three arrays except the original list. Except L, we also need a L_id array to record the id (index in the original list) of each element in L currently to help form predecessor list.