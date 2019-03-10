## Problem description

Given a linked list, repeatedly delete consecutive elements in the list and output the left and right elements of the deleted part.

## Algorithm analysis

As the list in this problem consists of only integers, we use array to represent the linked list. And to determine whether we reach out of the linked list, we add two dumb nodes at two ends.
Every time when we delete some consecutive nodes, just form the new link and output the involved two nodes.
The time complexity is O(n) where n is the number of deletion.

## Knowledge base

1. The linked list can be stored as an array. Each element stores the indices of its adjacent nodes.
2. To determine whether we have reached the end of the linked list, we use the dumb node.
   If this is a circular list, we can use one dumb node; if a non-circular list, we should use two dumb nodes for two ends.

