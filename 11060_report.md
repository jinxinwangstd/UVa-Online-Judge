## Problem description

There is a directed acyclic graph containing n vertices and m directed edges. Each edge means that the utility value of the source vertex is smaller than the utility value of the destination vertex. We need to sort them based on the increasing order of the utility value indicated by the directed edges.

## Algorithm analysis

We need to perform a topological sort to the vertices, and the algorithm we use is the Kahn's algorithm.
Because we use adjacent matrix for the graph representation, the time complexity is $O(V^2)$ where V is the number of vertices in the graph.

## Knowledge base

1. For Kahn's algorithm,
   The suitable representation of graph: Adjacent matrix, because we need to remove outcoming edges when we push vertex into the topological sorted list.
   We need to record the number of incoming edges for each vertex, so we need a separate array. In this way, we avoid the repeated traversal of graph to find vertices without incoming edges.
2. For the input, we need to be careful about some part of the input may be optional or missing. Be careful about the parameter about the number of input when their lower bound may be 0.
   Like in this problem, the m can be 0 which means there is no edge in the graph so the way we read input need a little twist.