#include <bits/stdc++.h>
#define FI
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
		}
		return;
	}
};

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int nT;
	scanf("%d", &nT);
	int n, m;
	while (nT--)
	{
		scanf("%d %d", &n, &m);
		vector< pair<int, ii> > edges;
		int u, v, w;
		for (int i = 0; i != m; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			edges.push_back(make_pair(w, ii(u - 1, v - 1)));
		}
		sort(edges.begin(), edges.end());
		vi mst_edges;
		int minimal = 0, sub_minimal = INT_MAX;
		UnionFind UF = UnionFind(n);
		for (int i = 0; i != m; ++i)
		{
			pair<int, ii> front = edges[i];
			if (!UF.isSameSet(front.second.first, front.second.second))
			{
				mst_edges.push_back(i);
				minimal += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		int num_mst_edges = (int) mst_edges.size();
		for (int i = 0; i != num_mst_edges; ++i)
		{
			UnionFind subUF = UnionFind(n);
			int cost = 0;
			for (int j = 0; j != m; ++j)
			{
				if (j != mst_edges[i])
				{
					pair<int, ii> front = edges[j];
					if (!subUF.isSameSet(front.second.first, front.second.second))
					{
						cost += front.first;
						subUF.unionSet(front.second.first, front.second.second);
					}
				}
			}
			sub_minimal = min(sub_minimal, cost);
		}
		printf("%d %d\n", minimal, sub_minimal);
	}
	return 0;
}
