## Problem description

Given a sequence of integers, return the 1-based index of an integer v in its kth appearance; if no such appearance, return 0

## Algorithm analysis

Analogous to adjacent list, we use a map to store the appearing indices of each key. So for each query, we just look for the corresponding appearing index for the key.
The total time complexity is O(NlogN) where N is the number of integers in the sequence. 

## Knowledge base

1. For the adjacent list representation of a graph, we have three types to define:

   - pair<int, int>: that is a pair of adjacent vertex index and the weight of the edge
   - vector<pair<int, int>>: all adjacent vertices and the corresponding weights for the edges
   - vector<vector<pair<int, int>>>: each vertex's adjacent vertices and its corresponding edge weight

   We can use such idea to record related information for each keys in a problem.