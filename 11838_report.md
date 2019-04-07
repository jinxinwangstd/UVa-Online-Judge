## Problem description

Given a directed graph, determine whether the graph is strongly connected, i.e. the graph contains only one strongly connected component.

## Algorithm analysis

To solve this problem, we need to identify all strongly connected components in the graph.
We can use tarjan's algorithm to find all SCC in a graph. It is a tweak of DFS algorithm.
When we traverse the graph using DFS, we maintain two vectors dfs_num and dfs_low. The dfs_num record the index of traversing through each node, so that the first node we traverse would have a corresponding 0 in dfs_num. The other vector dfs_low record the lowest node it can reach, in other words, it has a path to the node.
For a strongly connected component, there is only one node whose corresponding dfs_num value is the same as the dfs_low value, which is also the first node to be traversed; other nodes must have their dfs_low value less than their dfs_num value because they can reach any other node in the strongly connected component.
In this way, we can count the number of such node to find the number of SCC in the graph and identify all nodes in a strongly connected component.

## Knowledge base

1. vector can be used as stack.
   It has a method back() to access the top element of the stack, and a pop_back() method to pop out the top element in the stack.
2. Be careful about the vertex index. Sometimes it is 1-based index.
   If it is 1-based index, we need to tweak their indices when constructing the graph.