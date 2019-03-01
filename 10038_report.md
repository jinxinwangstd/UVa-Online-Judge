## Problem description

给定n个integer，确定所有相邻两数之间的差值绝对值是不是覆盖了[1, n-1]

## Algorithm analysis

使用一个bitset来记录[1, n-1]是否出现，这样比array节省空间；然后用linear scan计算出n-1个差值绝对值；最后判断bitset是否全部为1。Time complexity is O(n).

## Knowledge base

1. bitset: array of Booleans.
   constructor: N is the number of bits in a bitset.

   ```c++
   bitset<N> bs;
   ```

   set a single bit:

   ```c++
   bitset& set(size_t pos, bool var = true);
   ```

   test whether all bits are set:

   ```c++
   bool all() const noexcept;
   ```

2. Be careful of out of range when using operation results as index of assigning array values.
   For example, in this problem, the absolute difference between two successive elements may be out of range of the bitset.