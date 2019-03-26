## Problem description

Given a target amount V cents and a list of denominations for n coins, i.e. we have coinValue[i] (in cents) for coin type $i \in [0...n-1]$, what is the total number of different ways of making changes for any amount of money in cents. Note that we count that there is one way of making change for zero cent.

## Algorithm analysis

Dynamic programming solution:
In this problem, we can represent each state with two variables, the id of next considered coin type and remaining money. Let $\Phi(id, remM)$ to represent the number of different ways to make changes. Then we have such recurrence relation:
$\Phi(id, remM) = \sum_{0}^{remM/value(id)} \Phi(id+1, remM - n*value(id))$
Especially, when we consider the last coin type (no matter what value it has), there is only one way to make change (all in); if the remaining money is 0, there is also only one way to make change.
Suppose there is n coin types and M amount of money, there are $n \times M$ distinct states, so the overall time complexity is O(n*M^2) and the actual time complexity should be better than this.

## Knowledge base

1. We usually prefer to determine the state with integer variables which have consecutive values so that we can construct an 2D memoization table and fill it efficiently. For the variables which is not integers or sparse integers, we prefer to replace it with its id.
   For example, the coin type in this problem, we use its id to represent the state and access its value in an array.