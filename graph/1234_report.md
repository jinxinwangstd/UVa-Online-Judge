## Problem description

Given a undirected, weighted graph containing at least one cycle, we need put one camera in an edge of each cycle. The weight for each edge is the cost to arrange a camera in this edge. We need to determine the minimal cost to set up all need cameras for monitoring every cycle.

## Algorithm analysis

If the graph contains V vertices, the number of edges in its spanning tree would be V-1, and after that every time we add an edge we would form a cycle.
Now we need to select the least cost edge for every cycle, so we just construct a maximum spanning tree in the graph, and the left edges are the least cost for cycles in the graph.
To construct a maximum spanning tree, we just slightly modify the Kruskal's algorithm to sort the edges in decreasing order of edge weight, then we would get the maximum spanning tree.

## Knowledge base

1. The third argument for the sort() function must be a function name or function pointer, like greater< pair<int, ii> >(), not the function class name, like greater< pair<int, ii> >.