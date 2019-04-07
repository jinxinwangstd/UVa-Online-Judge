## Problem description

Given a weighted graph, we need to selected a set of edges to form the minimum spanning tree. In this problem, we have solved it with an original set of edges; now we have added some new edges, we need to solve it again and output the cost of two minimum spanning tree.

## Algorithm analysis

We use the Kruskal's algorithm to construct the minimum spanning tree.
Storing the graph in the edge list form, we first sort all edges in the ascending order of edge cost. Then we gradually add edges to the tree set until it contains V-1 edges.
Notice that we use a UnionFind data structure to avoid cycle in the minimum spanning tree.

## Knowledge base

1. The edge list representation is as following:

   ```c++
   typedef pair<int, int> ii;
   typedef vector< pair<int, ii> > edgeList;
   ```

   The reason why we put weight in the first element of an edge is that we can easily sort edges according to the edge weights.

2. We don't need to count the number of edges inside the minimum spanning tree set. The UnionFind data structure helps us.
   Once the minimum spanning tree forms, all nodes in the graph are in the same set.