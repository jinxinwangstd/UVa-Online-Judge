## Problem description

Given a graph with V vertices and E edges ($V \le 100$) and two vertices s and d, find the maximum possible value of dist\[s\]\[i\] + dist\[i\]\[d\] over all possible $i \in [0 ... V-1]$.

## Algorithm analysis

To solve this problem, we need the distance between any pair of vertices. We can call V times of Dijsktra's algorithm to solve it.
However, if the graph is small $(V \le 400)$, we can use Floyd Warshall's algorithm to get all pairs shortest path (APSP). Then enumerate all possible intermediate vertex and find the maximum distance.
The Floyd Warshall's algorithm takes $O(V^3)$ time and enumeration takes O(V) time, so the overall time complexity is $O(V^3)$.

## Knowledge base

1. Floyd Warshall's algorithm:
   The easy-to-implement algorithm to solve All Pairs Shortest Path (APSP) in $O(V^3)$ time.

   ```c++
   int g[maxn][maxn];	// The graph needs to be represented in adjacent matrix
   // If there is an edge between i and j, g[i][j] should be edge weight
   // If not, g[i][j] should be (INT_MAX / 2)
   // All self-edge should be 0, i.e. g[i][i] = 0
   for (int k = 0; k != V; ++k)
       for (int i = 0; i != V; ++i)
           for (int j = 0; j != V; ++j)
               g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
   // afterwards, g would store the shortest distance between i and j in g[i][j]
   ```

2. Be careful about the element value in a graph representation.
   Like in this problem, although the element where there is no edge should 1B, all diagonal element should be 0 because there is no distance between a vertex and itself.