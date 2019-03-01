## Problem description

Generate the next permutation (lexicographically) given a string (an array of characters)

## Algorithm analysis

Using C++ STL algorithm next_permutation()

## Knowledge base

1. next_permutation():

   ```c++
   template <class BidirectionalIterator>
   bool next_permutation (BidirectionalIterator first,
                          BidirectionalIterator last);
   ```

   This function rearranges the elements in a given range of a container into the next lexicographically greater permutation.
   If succeed, the function returns true; If there is no such permutation, this function returns false.

2. Permutation: different ways of arranging the members of a set into a sequence or order.
   For n elements in a set, the total number of permutations is n!.