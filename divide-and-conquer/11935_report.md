## Problem description

Imagine that you are an explorer trying to cross a desert. You use a jeep with a "large enough" fuel tank - initially full. You encounter a series of events throughout your journey such as "drive (that consumes fuel)", "experience gas leak (further reduces the amount of fuel left)", "encounter gas station (allowing you to refuel to the original capacity of your jeep's fuel tank)", "encounter mechanic (fixes all leaks)", or "reach goal (done)". You need to determine the smallest possible fuel tank capacity for your jeep to be able to reach the goal. The answer must be precise to three digits after decimal point.

## Algorithm analysis

Binary search solution:
If we know the fuel capacity of the car, we can simulate the driving process to determine whether this car can arrive the end.
The minimum possible tank volume p has a characteristic as following: [p, MAX] is safe for a car to arrive the end; [MIN, p] is impossible for a car to arrive the end. Thus we can use a binary search to search the value of p.
The time complexity is O(logN) where N is the value of the maximum volume of the tank.

## Knowledge base

1. Binary search of a floating answer value:
   The termination condition is that the difference between upper bound and lower bound value is smaller than epsilon.
2. Binary search of a integer answer value:
   The termination condition is that the upper bound is the same as the lower bound.
3. When simulating a process, some values should be valid throughout the process, while other values can be only determined at the end of the process. We call the former as "process values", and the latter as "result values". In simulation, we must carefully classify the variables into "process values" or "result values". For "process values", we should monitor and check them throughout the simulation.
   For example, the left fuel in the driving process should be a "process value", and we should ensure this variable should be non-negative every time encountering an event and at the end.