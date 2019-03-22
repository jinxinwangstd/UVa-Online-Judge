## Problem description

The team queue is a data structure where each element belongs to a team. When an element enters the queue, if there are some of its teammates already in the queue, it enters the queue right behind them; otherwise it enters the queue at the tail. Dequeuing is done like in normal queues: elements are processed from head to tail in the order they appear in the team queue.
Given a list of teams and their members and a sequence of commands (enqueues and dequeues), simulate the process.

## Algorithm analysis

Simulating problems related to queue data structures.
First, we need to record the members in each queue to determine whether an element's teammates are in the queue already later. Here we use a map to record each element with their team id.
Because each team is independent with each other, we don't need to maintain all queues in a big queue. We just need a queue to record the order of team id in the team queue. When the first element of a team enters the team queue, we push their team id into the team queue; when a team becomes empty, we pop out their team id from the team queue.
For every team, we use a vector to record their formed queue, so that we can quickly refer to the situation of a specific team.
The total time complexity is O(nlogn + m) where n is the total number of elements and m is the number of commands we simulate.

## Knowledge base

1. queue class in C++ does not have methods like clear() to make the queue object empty again. Thus in the programming contest, we should avoid declaring queue objects as global variables.
2. There may be more dequeue operations than the number of elements in the queue. So every time we pop out an element or check the front element in a queue, we must first check whether the queue is empty or not, and think about what is the appropriate behavior when the queue is empty.
3. Adding one level of indirection is really useful.
   Like in this problem, we add one indirection by only keeping the team id in the team queue, where through the team id we can find the queue of the specific team in a vector.