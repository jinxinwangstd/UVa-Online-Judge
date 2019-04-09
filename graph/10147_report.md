## Problem description

Given a set of Cartesian coordinates in a 2D flat plane, and we know that building a road between two coordinates is proportional to their distance. There are already some roads built between some coordinates, we need to determine what roads we need to build next to make all coordinates connected with the minimal cost.

## Algorithm analysis

In this problem, we need to start with some fixed edges and construct a minimum spanning tree. 
The solution is also simple, just running Kruskal's algorithm to select edges as normal until we finish constructing a tree.
The overall time complexity is the time complexity of Kruskal's algorithm, which is $O(E \times logV)$.

## Knowledge base

1. Be careful about the vertices indexing. Sometimes we need to transfer it to 0-based index, and transfer it back when we output the result.