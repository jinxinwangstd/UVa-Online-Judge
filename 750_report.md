## Problem description

In chess (with an 8*8 board), it is possible to place eight queens on the board such that no two queens attack each other. Determine all such possible arrangements given the position of one of the queens (i.e. coordinate (a, b) must contain a queen). Output the possibilities in lexicographical (sorted) order.

## Algorithm analysis

Recursive complete search solution:
We can view this problem as assign a row number to queens on each column respectively. Their coordinates must satisfy a set of constraints: the row number must be distinct and they cannot be at a same diagonal line.
Thus we can recursively assign row numbers to queens starting from column 1 to column 8, trying every possible positions for a queen. If one position is not valid, we go back to try another position; if valid, we continue to arrange the queen on the next column. This is called backtracking.
The time complexity is O(n^n) where n is the size of the board. In this problem, the number of total operations is approximately 8^8 = 17M.

## Knowledge base

1. The paradigm of recursive backtracking functions:
   1. Check whether we can terminate the backtracking, i.e. reaching the final state for a solution and return the final value.
   2. Check whether one of the next state is valid. If so, move to the next state; otherwise check another next state.
   3. If there is no valid next state, return a abnormal value to indicate this situation or just finish the function, not returning any value.