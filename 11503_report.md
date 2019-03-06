## Problem description

Given a set of links between a set of distinct nodes to be formed, after each link formed, return the size of the connected component they belong to. 

## Algorithm analysis

We use a UnionFind Set to record the set of nodes gradually becoming connected.
In addition, we need a map to record the node name with their corresponding ID.
The total time complexity is O(n) + O(nlogn) where n is the number of links to be formed.

## Knowledge base

1. UnionFind class with methods to return the size of a connected component that a node belongs to and clear the set:

   ```c++
   class UnionFind
   {
   private:
   	vi p, rank, size;
   public:
   	// Constructor
   	UnionFind(int N)
   	{
   		p.assign(N, 0);
   		rank.assign(N, 0);
   		size.assign(N, 1);
   		for (int i = 0; i != N; ++i)
   			p[i] = i;
   	}
   	// Recursively find the SetId that a node belongs to with path compression
   	int findSet(int i)
   	{
   		return p[i] == i ? i : (p[i] = findSet(p[i]));
   	}
   	// Determine whether two nodes belong to a same set
   	bool isSameSet(int i, int j)
   	{
   		return findSet(i) == findSet(j);
   	}
   	// Return the size of a connected component that a node belongs to
   	int findSetSize(int i)
   	{
   		return size[findSet(i)];
   	}
   	// Unite two sets
   	void unionSet(int i, int j)
   	{
   		if (!isSameSet(i, j))
   		{
   			int x = findSet(i);
   			int y = findSet(j);
   			if (rank[x] > rank[y])
   			{
   				p[y] = x;
   				size[x] = size[x] + size[y];
   			}
   			else
   			{
   				p[x] = y;
   				size[y] = size[y] + size[x];
   				if (rank[x] == rank[y])
   					++rank[y];
   			}
   		}
   		return;
   	}
   	// Reset the set to where all nodes are isolated
   	void clearSet()
   	{
   		int N = p.size();
   		for (int i = 0; i != N; ++i)
   		{
   			p[i] = i;
   			rank[i] = 0;
   			size[i] = 1;
   		}
   		return;
   	}
   };
   ```

2. For a problem using UnionFind data structure, we usually need to maintain a map to map the node name to its ID:

   ```c++
   map<string, int> records;
   int id = 0;
   
   int getId(string s)
   {
   	if (!records.count(s))
   		records[s] = ++id;
   	return records[s];
   }
   ```

   