## Problem description

Given a forest, determine how many trees and how many acorns are in there

## Algorithm analysis

For a tree graph, we have V - E = 1; For an acorn, we have V - E = 1. Thus we can conclude that in a forest, the number of connected components is V - E.
We use a bitset to track all vertices which have edges, therefore getting the number of acorns. Then read in all edges and vertices so that we can calculate the number of trees, which is the number of connected component minus the number of acorns.
The total time complexity is O(V+E)

## Knowledge base

1. The property of a tree:
   - V - E = 1
   - Connected