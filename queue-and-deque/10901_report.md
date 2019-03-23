## Problem description

There is a ferry across the river that can take n cars across the river in t minutes and return in t minutes. A car may arrive at either river bank to be transported by the ferry to the opposite bank. The ferry travels continuously back and forth between the banks so long it is carrying a car or there is at least one car waiting at either bank. Whenever the ferry arrives at one of the banks, it unloads its cargo and loads up to n cars that are waiting to cross. If there are more than n, those that have been waiting the longest are loaded. If there are no cars waiting on either bank, the ferry waits until one arrives, loads it (if it arrives on the same bank of the ferry), and crosses the river.
Given a non-decreasing sequence of car arriving time and river side, print their arrival time to the opposite bank in the same order.

## Algorithm analysis

Simulation problem with queue.
In this problem, each river bank can be viewed as a queue, and the ferry can also be viewed as a queue.
We use a loop structure to simulate the period in which the ferry starting from one side coming to the other side, no matter whether it loads some cars and unload them on the other side or not.
Because we need to output their arrival time in their input order, we need to maintain their id and record their arrival time in an array in their input order.

## Knowledge base

1. For simulation problem, think about how to split the simulation process into general repeated period. Then simulate such a period in a loop structure.