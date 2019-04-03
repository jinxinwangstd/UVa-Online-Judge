## Problem description

Given a graph in its adjacent list form, count the number of connected components in the graph.

## Algorithm analysis

Using graph traversal algorithm -- depth-first search to traverse through every node in the graph.
A depth-first search would go through all nodes in a connected component. After running one time of DFS, if there are nodes that are not yet visited, then it is in another connected component and we can start DFS from it again. In this way, we can count the number of connected components in the graph.
The overall time complexity is the time complexity of running DFS through a graph in adjacent list form, so it is O(V+E) where V is the number of vertices and E is the number of edges in the graph.

## Knowledge base

1. Starting from a node DFS would traverse through all vertices that is in the same connected components and generate a spanning tree rooted in the starting vertex.
   One of the meaning of DFS is detecting the connectivity between vertices and traverse them in once.
2. To represent a graph, we usually need to assign IDs to all vertices in the graph, like assigning IDs to different vertices with character label or string label.
   Sometimes it may need using a set or map to ensure unique IDs.
3. The adjacent list form of a graph can be stored in an array of vectors.