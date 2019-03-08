## Problem description

Given different options for each garment (e.g. 3 shirt models, 2 belt models, 4 shoe models, ...) and a certain limited budget, our task is to buy one model of each garment. We cannot spend more money than the given budget, but we want to spend the maximum possible amount.

## Algorithm analysis

Dynamic programming solution:
The state in this problem can be expressed as (money, g) where "money" is the amount of money left after purchasing "g" garments and g is the number of garments bought already.
The transitions between states are shop(money, g) = max(shop(money - price\[g][model], g+1)), which basically means that among those models, we choose the one which returns the maximum money we spent.
The total time complexity is O(MC*K) where M is the number of possible values of money, C is the number of garments we need to buy, and K is the maximum number of models for each garment.
The space complexity is O(MC).

## Knowledge base

1. Two prerequisites for dynamic programming to be applicable for a problem:
   - This problem has optimal sub-structures. For example, after choosing one garment with price p, the sub-problem is spent as much as possible money with the budget M-p to buy (C-1) garments
   - This problem has overlapping sub-problems. For example, all sub-problems are using M amount of money to buy g garments with different values of M and g. All solutions are consist of several sub-problems in them.
2. Using memoization we can store the answer of computed sub-problems and immediately return the answer if a following solution goes into this state. So in this way we can bound up the time complexity into the time of solving all sub-problems.