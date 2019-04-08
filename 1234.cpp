#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class UnionFind
{
private:
	vi p, rank;
public:
	UnionFind(int N)
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
	int isSameSet(int i, int j)
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
					rank[y]++;
			}
		}
		return;
	}
};

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int c;
	scanf("%d", &c);
	while (c--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		vector< pair<int, ii> > g;
		int u, v, w;
		for (int i = 0; i != m; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			g.push_back(make_pair(w, ii(u - 1, v - 1)));
		}
		// Modified Kruskal's algorithm to identify Maximum Spanning Tree
		sort(g.begin(), g.end(), greater< pair<int, ii> >());
		UnionFind UF = UnionFind(n);
		int i = 0, ret = 0;
		for (i = 0; i != m; ++i)
		{
			pair<int, ii> front = g[i];
			if (!UF.isSameSet(front.second.first, front.second.second))
				UF.unionSet(front.second.first, front.second.second);
			else		// the least cost edge in a cycle
				ret += front.first;
		}
		printf("%d\n", ret);
	}
	return 0;
}
