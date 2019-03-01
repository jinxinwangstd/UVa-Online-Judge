## Problem description

Given a spiral indexed square grid, determine the Cartesian coordinates (normal coordinates) of an element.

## Algorithm analysis

The trick is starting from the center cell, the index is 1^2, 3^2, 5^2, 7^2, and so on so forth when the row number and column number both increment. So we can determine which range the given index lies in, basically each range represents one square layer of the grid. Then we traverse through the spiral index increased route, scan each cell to see which is equal to the given index.
The time complexity is O(N) where N is the size of the square grid.

## Knowledge base

1. When we determine some boundary conditions, we should pick a general situation, not some extreme situation.
   For example, in this problem when I determine the conditions of traversing though one square layer, I pick up the outer most layer, that makes me set wrong conditions, ignoring I should track the min/max number of row index and column index for each layer. If I pick the middle layer, I can avoid such problem.

2. Integer Overflow:
   When a problem is involved with integer multiplication or exponent, we should carefully check whether there is a chance for integer overflow. If so, we need to use long integer or big integer class.