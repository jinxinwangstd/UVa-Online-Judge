## Problem description

Given a graph containing V vertices and E edges, we need to find the minimum of maximum edge weight among all possible paths between two vertices i and j.

## Algorithm analysis

We need to construct the minimum spanning tree in the graph. With the minimum spanning tree, we guarantee to have a unique path between any two vertices i and j. Then we just need to traverse through the tree, find the unique path between the two specified vertices and select the maximum edge among the path.
It takes $O(E \times logV)$ to construct a minimum spanning tree, and $O(V)$ to traverse the tree, as well as $O(V \times logV)$ to sort the edges along the path. So the overall time complexity is $O(E \times logV + V + V \times logV) = O(E \times logV)$.

## Knowledge base

1. Find the unique path between two vertices in a tree:
   We can modify the DFS algorithm if the tree is represented by adjacent list or adjacent matrix:

   ```c++
   int dfs_num[maxn];
   vi path;
   bool find_flag;
   
   void findPath(int s, int t) {
       dfs_num[s] = 1;
       if (s == t) {
           find_flag = true;						// find the path
           for (int i = 0; i != path.size(); ++i)
               printf("%d ", path[i].first);		// output the unique path
           return;
       }
       vii adjs = g[s];
       int num = (int) adjs.size();
       for (int i = 0; i != num; ++i) {
           if (!dfs_num[adjs[i].first]) {
               path.push_back(adjs[i]);
               findPath(adjs[i].first, t);
               path.pop_back();
           }
       }
       return;
   }
   ```

2. For every global variable, check whether it is initialized properly.
   For example, like the global minimum spanning tree in this problem, every time we read in a new graph, we need to clear the minimum spanning tree.