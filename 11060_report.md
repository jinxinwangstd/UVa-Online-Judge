## Problem description

There is a directed acyclic graph containing n vertices and m directed edges. Each edge means that the utility value of the source vertex is smaller than the utility value of the destination vertex. We need to sort them based on the increasing order of the utility value indicated by the directed edges. For the two vertex without any relationship, we should put the vertex appeared first in the input at the front.

## Algorithm analysis

We need to perform a topological sort to the vertices, and the valid order for this problem is unique. So we choose the Kahn's algorithm to produce the stable topological order.
The time complexity to traverse through the graph in adjacent list is O(V + E), and the time complexity to manipulate vertices with priority_queue is $O(V \times logV)$, so the overall time complexity is $O(V + E + V \times logV)$.

## Knowledge base

1. For Kahn's algorithm,
   - We need to maintain a vector to record the incoming degree of all vertices.
   - We should represent the graph in adjacent list and remove edges can be achieved by decrementing the incoming degree for specific vertex.
   - The queue we use to store unchecked vertices with zero incoming degree should be a priority queue.
2. For the input, we need to be careful about some part of the input may be optional or missing. Be careful about the parameter about the number of input when their lower bound may be 0.
   Like in this problem, the m can be 0 which means there is no edge in the graph so the way we read input need a little twist.