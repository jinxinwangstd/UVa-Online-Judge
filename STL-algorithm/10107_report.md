## Problem description

For a dynamically growing array, find the median each time when a new element added.

## Algorithm analysis

Each time find the index of median involved elements, sorting the whole array and find the involved elements, and then calculate the median.
The total time complexity is 1log1 + 2log2 + 3log3 + ... + nlogn

## Knowledge base

1. nth_element():

   ```c++
   template <class RandomAccessIterator>
   void nth_element (RandomAccessIterator first, 
                     RandomAccessIterator nth, 
                     RandomAccessIterator last);
   ```

   Rearranges the elements in the range [first, last), in such a way that the element at the nth position is the element that would be in that position in a sorted sequence. The other elements are left without any specific order.
   If we just need to pick a specific elements, which would be in a specific position in order, in a unsorted sequence, we don't need to sort the entire sequence, just use the nth_element().

2. For a number sequence of odd size, there is only one middle value. But we can consider it as two same middle values, and the median is the average of these two same middle values. In this way, the calculation processes for median of odd-size and even-size sequences are unified.