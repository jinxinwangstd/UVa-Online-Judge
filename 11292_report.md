## Problem description

There are n dragon heads and m knights (1 <= n, m <= 20000). Each dragon head has a diameter and each knight has a height. A dragon head with diameter D can be chopped off by a knight with height H if D <= H. A knight can only chop off one dragon  head. Given a list of diameters of the dragon heads and a list of heights of the knights, is it possible to chop off all the dragon heads? If yes, what is the minimum total height of the knights used to chop off the dragons' heads?

## Algorithm analysis

Greedy solution:
This problem is a bipartite matching problem, in the sense that we are required to match certain knights to dragon heads in a maximal or minimal fashion. We can solve it using a greedy solution.
We sort the dragon heads and knights in ascending order. Then we make linear scan in these two sequences. For each dragon head, the first knight that has larger height than its diameter is the lowest knight who can chop off its head, thus the most suitable knight, so we just choose it. After scanning all dragon heads, the solution hence becomes the optimal solution.
The time complexity is O(max(n, m) * log(max(n, m))) where n and m are sizes of the two sequences in this problem.

## Knowledge base

1. Sometimes when the console does not display anything, we can check the condition we wrote to terminate reading in the input. Maybe we just do not enter into the loop to read in the input.
   For example, in this problem the condition I wrote is

   ```c++
   while (scanf("%d %d", &n, &m) && !(n || m)) {
       // ...
   }
   ```

   where the correct condition is

   ```c++
   while (scanf("%d %d", &n, &m) && (n || m)) {
       // ...
   }
   ```

   The correct condition should be as long as one of n and m is non-zero.

2. Sorting is important in greedy solution, and the greedy solution is usually involved with linear scans through sequences in problem. The sorting order and the scanning direction is critical. Usually the ascending ordering is correct, but maybe sometimes we need the descending ordering. Thinking carefully!
   For example, in this problem the only way to solve it is sorting the two sequences in ascending order because we need to find the knight with minimal required height for each dragon head.

3. The variable which stores integer sum should be long int in case of integer overflow.