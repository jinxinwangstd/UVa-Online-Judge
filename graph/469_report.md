## Problem description

Given a 2D implicit grid and a cell in the grid, count the size of the connected component to which the cell belongs. Two adjacent cells having same labels are considered in a same connected component. Vertical, horizontal and diagonal cells are considered to be adjacent.

## Algorithm analysis

Using floodfill method twisted from DFS:
Basically we just started from a vertex and return the number of new vertices we found that have the same color as the starting vertex.
DFS ensures that we would access all adjacent vertices that has the same color, which is a connected component in total.

## Knowledge base

1. Two ways to implement the floodfill method (the difference is in the method to avoid cycles):
   One way is to use the dfs_num array to record the vertices we have visited:

   ```c++
   int floodfill(int r, int c, char c1) {
       if (r < 0 || r >= R || c < 0 || c >= C)
       	return 0;
       if (g[r][c] != c1)
       	return 0;
       if (dfs_num[r][c] == VISITED)
           return 0;
       dfs_num[r][c] = VISITED;
       int ans = 1;
       for (int d = 0; d != 8; ++d)
       	ans += floodfill(r + dr[i], c + dc[i], c1);
       return ans;
   }
   ```

   Another way is to change the vertex into another color after visiting (notice that the new color should not be any color in the original graph):

   ```c++
   int floodfill(int r, int c, char c1, char c2) {
       if (r < 0 || r >= R || c < 0 || c >= C)
       	return 0;
       if (g[r][c] != c1)
       	return 0;
       g[r][c] = c2;
       int ans = 1;
       for (int d = 0; d != 8; ++d)
       	ans += floodfill(r + dr[i], c + dc[i], c1);
       return ans;
   }
   ```

   