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

// Calculate the square of Cartesian distance between two Cartesian coordinates
int squareDis(const ii& u, const ii& v)
{
	int dr = abs(u.first - v.first), dc = abs(u.second - v.second);
	return dr * dr + dc * dc;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int nT;
	scanf("%d", &nT);
	while (nT--)
	{
		vii positions;
		int n;
		scanf("%d", &n);
		int x, y;
		for (int i = 0; i != n; ++i)
		{
			scanf("%d %d", &x, &y);
			positions.push_back(make_pair(x, y));
		}
		int m;
		scanf("%d", &m);
		set<ii> old_edges;
		UnionFind UF = UnionFind(n);
		int u, v;
		for (int i = 0; i != m; ++i)
		{
			scanf("%d %d", &u, &v);
			old_edges.insert(make_pair(u - 1, v - 1));
			UF.unionSet(u - 1, v - 1);
		}
		vector< pair<int, ii> > new_edges;
		for (int i = 0; i != n; ++i)
		{
			for (int j = i + 1; j != n; ++j)
			{
				if (!old_edges.count(make_pair(i, j)) && !old_edges.count(make_pair(j, i)))
				{
					new_edges.push_back(make_pair(squareDis(positions[i], positions[j]), ii(i, j)));
				}
			}
		}
		sort(new_edges.begin(), new_edges.end());
		int num = (int) new_edges.size();
		int num_built = 0;
		for (int i = 0; i != num; ++i)
		{
			pair<int, ii> front = new_edges[i];
			if (!UF.isSameSet(front.second.first, front.second.second))
			{
				printf("%d %d\n", front.second.first + 1, front.second.second + 1);
				UF.unionSet(front.second.first, front.second.second);
				num_built++;
			}
		}
		if (!num_built)
			printf("No new highways need.\n");
		if (nT)
			printf("\n");
	}
	return 0;
}
