## Problem description

Given 1 <= C <= 5 chambers which can store 0, 1, or 2 specimens, 1 <= S <= 2C specimens and a list M of the masses of the S specimens, determine which chamber should store each specimen in order to minimize "imbalance".
The "imbalance" is calculated as following:
$$
IMBALANCE = \sum_{i=1}^{C} CMi
$$
CMi is the Chamber Mass of chamber i
AM is the Average Mass of the chambers

## Algorithm analysis

Greedy solution:
We have two observations for this problem:

1. We should first make the empty chamber as less as possible.
2. If S > C, then S - C specimens must be paired with a chamber already containing a specimen.

So we can add some dummy specimens (0 mass) to the specimen set so that each chamber would have 2 specimens.
After sorting the specimen set, we can assign the kth largest and kth smallest specimens to the kth chamber. In this way, the balance (standard deviation) would be minimal.

## Knowledge base

1. This problem is a classical application of greedy algorithm called "load balancing".
2. Sorting usually plays an important role in greedy algorithms. Thus if there is no obvious greedy strategy, try sorting the data or introducing some tweak.
   For example, in this problem, the dummy specimens are the tweaks brought by us. After introducing the dummy specimens, there appears a general assigning strategy which is optimal.
3. Pigeonhole principles: also called dirichlet's drawer principle. If there are n pigeons and m holes and n > m, we can conclude that there is at least one hold that contains more than one pigeon.
4. accumulate() is the reinforced version of sum() in C++