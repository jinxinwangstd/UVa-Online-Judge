## Problem description

Given a source sequence of integers (all different) and a target sequence of integers (all different), and a stack to store integers, determine whether we could use a sequence of push and pop operations to turn the source sequence into the target sequence.

## Algorithm analysis

We can simulate the transferring process, that is using a stack to generate the target sequence elements one by one. We can split our process into rounds, and every round we have three options: 1. get an element from the source sequence and push it into the stack; 2. get an element from the source sequence and transfer it into the target sequence (equivalent to consecutive push and pop); 3. pop an element from the stack and get it into the target stack. Every round we either get a source element or make a target element or do it both. If all source elements are taken and the target sequence are not yet completed, then it is failed.
The total time complexity is O(n) where n is the number of elements in the sequences. 

## Knowledge base

1. Frequently used stack methods in C++:

   ```c++
   explicit stack(const container_type& cntr);
   bool empty() const;
   size_type size() const;
   reference& top();
   void push (const value_type& val);
   void pop();
   ```

2. Every time when you use top() on a stack, first check whether it is empty using empty(), otherwise you may get segmentation fault.
   Analogous to before accessing an element in an array, we have to check whether the index is in bound.