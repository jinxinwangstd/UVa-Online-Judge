## Problem description

Given a set of distinct nodes, and some of them are connected with links. At first three nodes are activated. If a node is inactivated but connected to three activated nodes, next year it become activated. Determine it takes how many years to activate all nodes or never.

## Algorithm analysis

Graph problems.
Since the size of this graph is small (the maximum number of nodes is 26), we can simply simulate the activating process. Storing the graph with adjacent list, every time we just linear scan every inactivated node, check its adjacent nodes and determine whether it can become activated next year. If one year there is no node being activated, then the graph will never become all activated.
In this method, we also need a set to record all activated nodes.
The time complexity is O(n^3*logn) where n is the number of nodes in this graph.

## Knowledge base

1. KISS Principle:
   Keep it Simple and Stupid
2. Two implementation of adjacent list for a graph:
   vector<vector<pair<int, int> > > g
   Or
   map<int, vector<pair<int, int> > > g