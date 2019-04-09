## Problem description

There is a graph containing P vertices each has a Cartesian coordinate. We can build two kinds of edges between them, one kind has no cost and at most S of them; the other has no limit of number but has a cost of exactly the distance between two vertices. We need to know the maximum distance of the second edge we built in the graph when we assign edges to make the graph connected with minimal cost.

## Algorithm analysis

As there are S first kind of edges that have no cost and no distance limit, we should use the second kind of edges to build S connected components with minimum cost, then the first kind of edges would make all connected components connected with each other.
The solution is also simple. We just need to run Kruskal's algorithm to construct minimum spanning tree, but after we get the desired number of connected components, we terminate the algorithm.

## Knowledge base

1. We can slightly modify the UnionFind Set data structure to record the number of connected components in the graph.