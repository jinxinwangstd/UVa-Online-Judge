## Problem description

Give a big 2D grid and a small 2D grid, count the number of appearances in the big grid of the small grid, in its four rotated forms.

## Algorithm analysis

To count the number of appearance of small 2D array in a big 2D array, just slide through all possible positions, compare corresponding elements.
To rotate a 2D array, we need a temporary 2D array to hold the original one, and copy each column to the corresponding row of the new 2D array (1st column to 1st row, 2nd column to 2nd row, ...), then we got the 90 degree clockwise rotated 2D array.
The time complexity is O(MN^2) where M is the size of big 2D array and N is the size of small 2D array.

## Knowledge base

1. Rotate a 2D array clockwise and counter-clockwise:
   Clockwise: 1st column in the original array corresponds to 1st row in the new array, 2nd column in the original array corresponds to 2nd row in the new array, and so on.
   Counter-clockwise: 1st row in the original array corresponds to 1st column in the new array, 2nd row in the original array corresponds to 2nd column in the new array, and so on.
   In addition, we need a temporary grid to hold the original array.