## Problem description

There are 0 < n <= 8 movie goers. They will sit in the front row in n consecutive open seats. There are 0 <= m <= 20 seating constraints among them, i.e. movie goer a and movie goer b must be at most (or at least) c seats apart. The question is simple: How many possible seating arrangements are there?

## Algorithm analysis

Complete search solution:
We enumerate all permutations of size n and then check whether it satisfies the constraints.
The number of total operations we would execute is at most 20 * 8! = 806400, so it is solvable.

## Knowledge base

1. Use next_permutation() to generate permutations for a sequence of elements in a container
2. The function find() in <algorithm> can be used on elements in an array, and it would return a pointer to the element type.
3. The iterators can do arithmetic operations "+" and "-" 

