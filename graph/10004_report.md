## Problem description

Given a undirected, strongly connected graph without self-cycle, determine whether this graph can be bi-colored so that no two adjacent nodes have the same color.

## Algorithm analysis

This problem is equivalent to checking whether a graph is bipartite.
Use a tweak of BFS to color every node. If there are two nodes associated with an edge have the same color, then the graph cannot be bi-colored.

## Knowledge base

1. Why BFS can be used to check whether a graph is bipartite:
   In a BFS spanning tree, the nodes in two consecutive levels are adjacent so that they must be colored differently.
   In addition, BFS would traverse all edges in the graph, so that if there is an edge between two adjacent nodes, we would find it.