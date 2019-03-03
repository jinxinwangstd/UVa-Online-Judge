## Problem description

Given a bag-like container and a series of push and pop operations and their corresponding results, determine whether the bag-like container is a stack, or queue, or priority_queue.

## Algorithm analysis

Simulation method: we maintain a stack, a queue and a priority queue at the same time and simulate the operations in those container. Then every time the container pops out an element, we check whether it is the same as the elements returned by our own maintained containers.
One thing to notice is that the series of operations may not be all valid for our own maintained containers, so every time we pop out elements, first check whether the pop operation is valid, that is whether the container is not empty.
If the number of operations is N, the total time complexity is O(NlogN).

## Knowledge base

1. When scanf() run into the EOF in the input stream, it will return EOF, not the usual return value, which is the number of variables read in. Thus if we want to read
   input until running into EOF, the correct condition is

   ```c++
   while (scanf("%d", &n) != EOF) {
       // ...
   }
   ```

2. The function to return the front element in C++ queue class is front(), not top().

