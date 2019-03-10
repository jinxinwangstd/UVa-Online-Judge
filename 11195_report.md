## Problem description

Given an n*n chessboard (3 <= n <= 15) where some of the cells are bad (queens cannot be placed on those bad cells), how many ways can you place n queens in the chessboard so that no two queens attack each other? Note: Bad cells cannot be used to block queens' attack.

## Algorithm analysis

Recursively complete search solution:
Similar to UVaOJ 750, we recursively assign row numbers to queens on column from 1 to 7. But here we need more techniques to speed up our complete search.
One of the major time consuming part in the complete search solution of UVaOJ 750 is every assigned queens needs to be checked with all previous queens with constraints on rows and diagonals, which would be O(n). Here we use three bitsets to record the rows, left diagonals and right diagonals, so every newly assigned queen only needs to check whether its corresponding row and diagonals is available or not, which would be O(1).

## Knowledge base

1. For a chess board of size n, the numbers of left diagonals and right diagonals are both $2 * n - 1$. 
   For a specific cell in the board with row number r and column number c, its corresponding left diagonal index is r - c, and its corresponding right diagonal index is r + c.
   Thus, we can conclude that the range of left diagonal index is [-(n - 1), n - 1] and the range of right diagonal index is [0, 2 * (n - 1)].
   To fit the index of arrays in C/C++, we usually give an offset to the left diagonal index of a cell. In this way, the left diagonal index is (r - c + n - 1) and the right diagonal index is (r + c).
2. When we use some global flag variables in recursive complete search (DFS), be careful to restore the flag variables when going back to the upper state (parent node).
   For example, in this problem, after every time we finished exploring one next state, we need to restore the flag variable set for this next state to avoid affecting another next state.
3. Be careful about the second parameter of fgets() function. If the size you read in is too small, you may not be able to reach the delimiter of the line, in other words, not be able to finish reading this line.
   For example, in this problem when I try to read a line in the board of size n, there are at least n+1 characters, but I only read in n characters, which causes bugs.
4. The arrays declared in the program should be a little bigger than the maximum value stated in the problem.
   Like in this problem, when I declared the 2D array as 15 * 15, which is the maximum value as stated in the description, the result is wrong answer. After I change it to 20 * 20, then it is accepted.