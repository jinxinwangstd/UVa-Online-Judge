## Problem description

n sprinklers are installed in a horizontal strip of grass L meters long and W meters wide. Each sprinkler is centered vertically in the strip. For each sprinkler, we are given its position as the distance from the left end of the center line and its radius of operation. What is the minimum number of sprinklers that should be turned on in order to water the entire strip of grass? Constraint: n < 10000.

## Algorithm analysis

This problem is actually a variant of the well known greedy problem called the interval covering problem. But there is a twist in geometry. Instead of covering a one-dimensional length, in this problem we need to cover a rectangle area.
We can transform this problem into the traditional interval covering problem. The key is that using Pythagorean theorem to calculate the actual horizontal interval covered by a sprinkler. Then we can apply the classical solution for the interval covering problem.
Sorting the intervals according to the increasing left boundaries and decreasing right boundaries if there is a tie. Then make a linear scan of every interval, choose the interval which overlaps with the left interval and reaches the far-most right boundary.
The overall time complexity is O(NlogN) where N is the number of intervals.

## Knowledge base

1. Anytime when we want to calculate an exponents (even square), unless we are pretty sure that the result never occur integer overflow, otherwise we should use pow(base, exponent) to calculate the exponents instead of multiplication, especially the operands are integers.
   The pow() would cast the operands to "double" type before doing calculation, which would minimize the risk of integer overflowing.
2. When we use sqrt() functions, be aware of thinking about when the argument would be negative. Usually we would receive a domain error when we pass a negative argument to the sqrt() function, but in the UVaOJ, the result is unpredictable.
3. Every time when we want to refer to an element in a container, first check whether it is valid to refer to this element, like whether the container is empty or whether it has been beyond the boundary. Such problem are easier to happen when we traverse the elements in a container. For example, when we traverse an array or a vector then the index of element has been beyond the boundary; or when we manipulate a stack then the stack has been empty.
   In this problem, I forgot to check whether there is left sprinkler to use when I traverse all sprinklers, which caused segmentation fault.