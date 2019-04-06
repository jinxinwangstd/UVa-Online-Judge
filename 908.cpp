#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, k, m;

class UnionFind
{
private:
	vi p, rank;
public:
	UnionFind(int n)
	{
		p.assign(n, 0);
		rank.assign(n, 0);
		for (int i = 0; i != n; ++i)
			p[i] = i;
	}
	int findSet(int u)
	{
		return p[u] == u ? u : p[u] = findSet(p[u]);
	}
	bool isSameSet(int u, int v)
	{
		return findSet(u) == findSet(v);
	}
	void unionSet(int u, int v)
	{
		if (!isSameSet(u, v))
		{
			int x = findSet(u), y = findSet(v);
			if (rank[x] > rank[y])
				p[y] = x;
			else
			{
				p[x] = y;
				if (rank[x] == rank[y])
					++rank[y];
			}
		}
	}
};

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int caseNo = 0;
	while (scanf("%d", &n) != EOF)
	{
		printf("%s", caseNo ? "\n" : "");
		caseNo++;
		int u, v, w;
		vector< pair<int, ii> > edges;
		int old_cost = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			old_cost += w;
		}
		scanf("%d", &k);
		for (int i = 0; i != k; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			edges.push_back(make_pair(w, ii(u - 1, v - 1)));
		}
		scanf("%d", &m);
		for (int i = 0; i != m; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			edges.push_back(make_pair(w, ii(u - 1, v - 1)));
		}
		sort(edges.begin(), edges.end());

		int new_cost = 0;
		UnionFind UF(n);
		for (int i = 0; i != m + k; ++i)
		{
			pair<int, ii> front = edges[i];
			if (!UF.isSameSet(front.second.first, front.second.second))
			{
				new_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%d\n%d\n", old_cost, new_cost);
	}
	return 0;
}
