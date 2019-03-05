## Problem description

Given a series of operations of connecting two nodes and query whether two nodes are connected, determine the number of successful queries (two nodes are connected) and the number of unsuccessful queries (two nodes are not connected)

## Algorithm analysis

Using a UnionFind Set to simulate all the queries.

## Knowledge base

1. The UnionFind class in C++:

   ```c++
   typedef vector<int> vi;
   
   class UnionFind {
   private:
   	vi p, rank;
   public:
   	UnionFind(int N) {
           p.assign(N, 0);
           rank.assign(N, 0);
           for (int i = 0; i != N; ++i)
           	p[i] = i;
   	}
   	int findSet(int i) {
           return p[i] == i ? i : (p[i] = findSet(p[i]));
   	}
   	bool isSameSet(int i, int j) {
           return findSet(i) == findSet(j);
   	}
   	void unionSet(int i, int j) {
           if (isSameSet(i, j)) {
               int x = findSet(i);
               int y = findSet(j);
               if (rank[x] > rank[y])
               	p[y] = x;
               else {
                   p[x] = y;
                   if (rank[x] == rank[y])
                   	rank[y]++;
               }
           }
   	}
   };
   ```

2. When we use a member function of a class, we need to specify the class instance; when we use a non-member function of a class, we need to specify the name space.

