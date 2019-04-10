#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int maxn = 1000;
const int maxc = 1000;
const int maxs = maxn * maxc;

// Assign a unique ID to each state s. s.first is city id and s.second is fuel units
int getID(const ii& s)
{
	return s.first * maxc + s.second;
}

// Reversely get the fuel units from the id of a state
int getFuel(int id)
{
	return id % maxc;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	vi fuel_price;
	int p;
	for (int i = 0; i != n; ++i)	// read in fuel price
	{
		scanf("%d", &p);
		fuel_price.push_back(p);
	}

	vector<vii> g;
	g.assign(maxs, vii());
	// add the second type of edges to the graph, which is adding one fuel unit with cost of the fuel price
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != maxc; ++j)
		{
			ii v1 = make_pair(i, j);
			ii v2 = make_pair(i, j + 1);
			g[getID(v1)].push_back(make_pair(getID(v2), fuel_price[i]));
		}
	int u, v, d;
	// add the first type of edges to the graph, which is moving from one city to the other with no cost, consuming d fuel units
	for (int i = 0; i != m; ++i)
	{
		scanf("%d %d %d", &u, &v, &d);
		for (int j = d; j <= maxc; ++j)
		{
			ii v1 = make_pair(u, j);
			ii v2 = make_pair(v, j - d);
			ii v3 = make_pair(v, j);
			ii v4 = make_pair(u, j - d);
			g[getID(v1)].push_back(make_pair(getID(v2), 0));
			g[getID(v3)].push_back(make_pair(getID(v4), 0));
		}
	}
	int q;
	scanf("%d", &q);
	int c, s, e;
	while (q--)
	{
		scanf("%d %d %d", &c, &s, &e);
		// Dijkstra routine
		vi dist(maxs, INT_MAX);		// record the minimum distance so far
		dist[getID(make_pair(s, 0))] = 0;
		priority_queue< ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, getID(make_pair(s, 0))));
		// Update distance to all other vertices
		while (!pq.empty())
		{
			ii front = pq.top();
			pq.pop();
			int d = front.first, u = front.second;
			if (d > dist[u])	// check whether it contains the minimum distance
				continue;
			int num = (int) g[u].size();
			for (int i = 0; i != num; ++i)
			{
				ii v = g[u][i];
				if (getFuel(v.first) <= c && dist[u] + v.second < dist[v.first])
				{
					dist[v.first] = dist[u] + v.second;		// relax operation
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		int ret = INT_MAX;
		for (int i = 0; i <= c; ++i)	// compare the distance to all valid ending state
			ret = min(ret, dist[getID(make_pair(e, i))]);
		if (ret == INT_MAX)
			printf("impossible\n");
		else
			printf("%d\n", ret);
	}
	return 0;
}
