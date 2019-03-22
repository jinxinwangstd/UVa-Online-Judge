## Problem description

A cargo carrier travels among several cargo stations in circular order (1 to 2, 2 to 3, 3 to 1). The carrier is a stack with finite capacity, and each station is a queue with same finite capacity. The cargo that carriers take has target station. When a carrier arrive at a station, it first unloads the cargo to the station (for the cargo whose target station is here, they just gone) until the station is full or the carrier is empty. Then it loads the cargo from the station until the station is empty or the carrier is full. Loading and unloading a cargo needs 1 minute and traveling from one station to another needs 2 minutes.
Given a bunch of stations with cargo and an empty carrier, simulate the process and determine the total time the carrier needs to distribute all cargo to their corresponding stations.

## Algorithm analysis

Simulation problem with queues and stacks.
We need to maintain a counter of empty stations in the simulation. That would serve as our termination condition. When the stacks in all stations are empty, the carrier can stop working.
The rest is just simulation of the unloading and loading process.

## Knowledge base

1. The counter variable in a program should have general meaning.
   Like in this problem, the counter is the number of non-empty stations throughout the simulation process. Based on this meaning, we should increment the counter while the carrier starting to unload to an empty station. That is natural and absolutely correct because we are sticking to the meaning of the variable.
2. Be careful about the loop condition covers all kinds of situations.
   For example in this problem, when unloading cargo from the carrier, there are two kinds of mutual exclusive possibilities for the station and three kinds of mutual exclusive possibilities for the carrier.
   The station may be full or not full. The carrier may be empty, having cargo on top whose target is not this station, or having cargo on top whose target is this station. So there are 6 kinds of combinations and we should specify at each combination whether we should terminate the loop. That is called All Inclusive and Mutual Exclusive. The principles of AI and ME are important when we decide logic flow.