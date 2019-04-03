## Problem description

Vertex X dominates vertex Y if every path from the a start vertex (vertex 0 for this problem) to Y must go through X. If Y is not reachable from the start vertex then Y does not have any dominator. Every vertex reachable from the start vertex dominates itself. Given a directed graph, determine the dominators of every vertex.

## Algorithm analysis

To determine whether a vertex Y is dominated by another vertex X, we need two piece of information. One is whether the vertex Y is reachable from the start vertex; another is whether the vertex Y is reachable from the start vertex after removing the vertex X. So we need run two times of DFS to determine the domination of the vertex X to the vertex Y. In total, we need to run (V+1) times of DFS to determine the domination of every vertex to all other vertices.
The overall time complexity of the algorithm is O(V^2 + VE) where V is the number of vertices and E is the number of edges in the graph.

## Knowledge base

1. To remove a vertex while traversing a graph, we just need to return when reaching that vertex instead of explicitly clear the vertex and its edges in the graph.
   For example, in this problem, we use a global variable to record the id of the vertex we need to remove, and when running dfs function, as long as we reach this vertex, we just return from the function without expanding.
2. Using DFS to traverse through a graph in the adjacent matrix form takes O(V^2) time because we need to explicitly go through all other vertices when reaching a vertex and check whether they have edge between, so we would access through all elements in the adjacent matrix, which is O(V^2).