#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int maxc = 100 + 5;
vii mst[maxc];			// minimum spanning tree
int dfs_num[maxc];		// dfs_num to avoid cycle
vi path;				// array of edges indicating the path we are traversing
bool find_flag;			// flag of finding path or not

class UnionFind
{
private:
	vi p, rank;
	int num_sets;
public:
	UnionFind(int N) : num_sets(N)
	{
		p.assign(N, 0);
		rank.assign(N, 0);
		for (int i = 0; i != N; ++i)
			p[i] = i;
	}
	int findSet(int i)
	{
		return p[i] == i ? i : p[i] = findSet(p[i]);
	}
	int getNumSets()
	{
		return num_sets;
	}
	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j)
	{
		if (!isSameSet(i, j))
		{
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
				p[y] = x;
			else
			{
				p[x] = y;
				if (rank[x] == rank[y])
					++rank[y];
			}
			--num_sets;
		}
		return;
	}
};

// Find the path from vertex s to vertex t in a tree using dfs
void findPath(int s, int t)
{
	dfs_num[s] = 1;
	if (s == t)		// reach the destination
	{
		sort(path.begin(), path.end(), greater<int>());
		printf("%d\n", path[0]);	// output the maximum edge in the path
		find_flag = true;
		return;
	}
	vii adjs = mst[s];
	int num = (int) adjs.size();
	for (int i = 0; i != num; ++i)
	{
		if (!dfs_num[adjs[i].first])
		{
			path.push_back(adjs[i].second);		// record the edge in the path
			findPath(adjs[i].first, t);
			path.pop_back();					// restore the path by removing this edge
		}
	}
	return;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int c, s, q, caseNo = 0;
	while (scanf("%d %d %d", &c, &s, &q) == 3 && (c || s || q))
	{
		printf("%s", caseNo ? "\n" : "");
		printf("Case #%d\n", ++caseNo);
		vector< pair<int, ii> > edges;
		int u, v, w;
		for (int i = 0; i != s; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			edges.push_back(make_pair(w, ii(u - 1, v - 1)));
		}
		for (int i = 0; i != maxc; ++i)		// clear the minimum spanning tree
			mst[i].clear();
		// Kruskal's algorithm to construct the minimum spanning tree
		sort(edges.begin(), edges.end());
		UnionFind UF(c);
		for (int i = 0; i != s; ++i)
		{
			pair<int, ii> front = edges[i];
			if (!UF.isSameSet(front.second.first, front.second.second))
			{
				UF.unionSet(front.second.first, front.second.second);
				mst[front.second.first].push_back(make_pair(front.second.second, front.first));
				mst[front.second.second].push_back(make_pair(front.second.first, front.first));
			}
		}
		int c1, c2;
		for (int i = 0; i != q; ++i)
		{
			scanf("%d %d", &c1, &c2);
			memset(dfs_num, 0, sizeof(dfs_num));
			path.clear();
			find_flag = false;
			findPath(c1 - 1, c2 - 1);	// find the minimax edge from c1 to c2
			if (!find_flag)
				printf("no path\n");
		}
	}
	return 0;
}
