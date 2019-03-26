## Problem description

Given n places and their positions and a starting position, compute the minimal cost of making a tour that starts from the starting position, goes through all other places exactly once, and finally returns to the starting position.

## Algorithm analysis

Dynamic programming solution:
Notice there are many repeated sub-problems, we consider dynamic programming algorithm.
We can represent the state with two variables, the current place id and the set of visited places. To efficiently represent the set, we can use a bitset, which can be represented with an integer. Let $\Phi(pos, visited)$ to be the minimum distance to travel through all left places and back to start. Then we have such recurrence relation:
$\Phi(id, visited) = min(dist[id, next] + \Phi(next, visited | next))$
Suppose there are n places in the problem, so we would have $n \times 2^n$ distinct states, and determine each state need O(n) time. The overall time complexity is $O(n^2 \times 2^n)$.

## Knowledge base

1. To efficiently represent a set, we can consider a bitset, which is equivalent to an integer.
   For example, in the TSP, we can use bitset to represent all places we have visited with assigning all places with consecutive ids.