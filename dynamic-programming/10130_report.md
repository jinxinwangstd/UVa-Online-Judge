## Problem description

Given n items, each with its own value $V_i$ and weight $W_i$, $\forall i \in [0...n-1]$, and a maximum knapsack size S, compute the maximum value of items that we can carry, if we can either ignore or take a particular item.

## Algorithm analysis

Dynamic programming solution:
We can represent the state with two variables, the next considered item id and the remaining weight. Let $\Phi(id, remW)$ to be the maximum value by buying items from id to the last one with remW weight. Then we have such recurrence relation:
$\Phi(id, remW) = max(\Phi(id+1, remW), value(id) + \Phi(id+1, remW-weight(id)))$
Suppose there are n items and W amount of weight, so we have $n \times W$ distinct states and we can determine each state in O(1). Thus the overall time complexity is O(n*W).

## Knowledge base

1. Reading the problem description carefully.