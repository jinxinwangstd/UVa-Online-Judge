## Problem description

Given two group of integers (may have duplicates), every time extract k largest numbers from two groups, and make absolute difference between each pair of integers, the result go back to the group of the larger integer in this pair. Determine which group would become empty first or both become empty at the same time and output the left elements.

## Algorithm analysis

Using two multiset objects to record the elements in two groups, and simulate the process until one of the group becomes empty.

## Knowledge base

1. 如果遇到模拟题需要模拟整个过程时，我们往往可以将整个过程划分为重复的小单元，如游戏中的一轮，或者linear scan中检视每个元素。要仔细分析每个小单元的过程，力求过程模拟完全准确无误。
   例如本题中，每一轮战斗就是一个小单元。该单元从分配战士前往不同的战场开始（相当于对元素进行排序），然后每个战场依次对决，产生结果（相当于比较做差），最后将生还者重新编入队伍，准备下一轮战斗（元素重新存入集合）为结束。由于我们每次从容器中取出第一个元素进行比较做差，相当于委派这个元素进行战斗，所以所有容器中的元素都有可能被分配进入战斗，因此每次战斗的生还者不可以立即存入容器，否则存在再次被分配战斗的可能性，而这与题意不符。

2. multiset可以用于存储可能存在重复的多个元素，并且容器内元素是有序的。
   定义一个降序的multiset：

   ```c++
   multiset<int, greater<int> > s;
   ```

   常用method:

   ```c++
   bool empty() const noexcept;
   size_type size() const noexcept;
   iterator insert(const value_type& val);
   template <class InputIterator>
   	void insert(InputIterator first, InputIterator last);
   ```

   

3. multiset内部使用Binary Search Tree实现，基本操作的时间复杂度均为O(logn)

