## Problem description

Given a graph with vertices and possible undirected, weighted edges, selected a set of edges to make the graph connected with minimal cost. We need to give the two best plan, which means the set of edges with the minimal cost and the set of edges with the second minimal cost.

## Algorithm analysis

We can find the minimum spanning tree through Kruskal's algorithm in $O(E \times logV)$.
Also we can observe that the second minimum spanning tree only have one different edge compared to the MST.
Thus, we can find the second minimum spanning tree by blocking each edge in the MST and run Kruskal's algorithm to construct the minimum spanning tree. Among those spanning tree we select the least one and it would be the second minimum spanning tree.
The overall time complexity would be $O(E \times logV + V \times E)$ where E is the number of edges and V is the number of vertices.

## Knowledge base

1. When we use the Kruskal's algorithm, we need to consider that whether the selected edge set could construct a tree or make the graph connected. If there is a possibility that it could not, we need to check the number of connected components after each time running Kruskal's algorithm.
   Especially in the settings when we run Kruskal's algorithm on part of edges. Maybe all edges could make the graph connected but part of them could not. For example, this problem.
2. Don't use "min" and "max" as the name of variables, because they are function names in the standard template library in C++.