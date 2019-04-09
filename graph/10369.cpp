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

int squareDis(const ii& u, const ii& v)
{
	int dr = u.first - v.first, dc = u.second - v.second;
	return dr * dr + dc * dc;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int nT;
	scanf("%d", &nT);
	int s, p;
	while (nT--)
	{
		scanf("%d %d", &s, &p);
		vii positions;
		int x, y;
		// Read in all positions in the graph
		for (int i = 0; i != p; ++i)
		{
			scanf("%d %d", &x, &y);
			positions.push_back(make_pair(x, y));
		}
		vector< pair<int, ii> > edges;
		// Calculate all possible edges we can build
		for (int i = 0; i != p; ++i)
			for (int j = i + 1; j != p; ++j)
				edges.push_back(make_pair(squareDis(positions[i], positions[j]), ii(i, j)));
		// Kruskal's algorithm
		UnionFind UF = UnionFind(p);
		sort(edges.begin(), edges.end());
		int ret = 0, num = (int) edges.size();
		for (int i = 0; i != num; ++i)
		{
			pair<int, ii> front = edges[i];
			if (!UF.isSameSet(front.second.first, front.second.second))
			{
				UF.unionSet(front.second.first, front.second.second);
				if (UF.getNumSets() == s)		// there are S connected components in the graph
				{
					ret = front.first;			// record the last edges to form S connected components
					break;
				}
			}
		}
		printf("%.2f\n", sqrt(ret));
	}
	return 0;
}
