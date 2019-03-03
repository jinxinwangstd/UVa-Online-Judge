## Problem description

Given a group of integers, get the sum of those integers by adding two integers every time with smallest cost, where the cost of each addition is the result of the addition, and the total cost is the sum of costs of all additions.

## Algorithm analysis

Greedy solution: every time we select the most smallest two integers to get the sum and insert back into the group of integers. We can prove that this solution have the smallest cost.
To efficiently select smallest elements in a group, we use a priority queue to store the group of integers, including the intermediate results.
The total time complexity is O(NlogN) where N is the number of integers in the original group.

## Knowledge base

1. Frequently used methods for class priority_queue:

   ```c++
   bool empty() const;
   size_type size() const;
   const_reference top() const;
   void push(const value_type& val);
   void pop();	
   ```