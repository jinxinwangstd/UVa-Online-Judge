#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int UNVISITED = -1;
const int maxn = 2000 + 5;
int n, m, dfs_counter, num_scc;
vi dfs_num;		// the index of traversing in DFS
vi dfs_low;		// the lowest index a node can reach
vi S;			// stack for storing vertices
vi visited;		// record of whether it is in the DFS spanning tree
vi g[maxn];		// graph represented in adjacent list

// Tarjan's algorithm to identify strongly connected components
void tarjanSCC(int u)
{
	dfs_num[u] = dfs_low[u] = dfs_counter++;	// set initial dfs index
	S.push_back(u);
	visited[u] = 1;								// it is in the dfs spanning tree
	int num_adj = (int) g[u].size();
	for (int i = 0; i != num_adj; ++i)
	{
		int v = g[u][i];
		if (dfs_num[v] == UNVISITED)	// have not been traversed
			tarjanSCC(v);
		if (visited[v])					// it is in the dfs spanning tree
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_num[u] == dfs_low[u])	// root of a strongly connected component
	{
		num_scc++;
		while (1)					// pop out members of this SCC
		{
			int v = S.back();
			S.pop_back();
			visited[v] = 0;			// remove it from the spanning tree
			if (u == v)				// all members of this SCC (including root) have been poped out
				break;
		}
	}
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d %d", &n, &m) && n && m)
	{
		for (int i = 0; i != n; ++i)	// clear the graph
			g[i].clear();
		for (int i = 0; i != m; ++i)
		{
			int u, v, d;	// the id of nodes are 1-based index
			scanf("%d %d %d", &u, &v, &d);
			g[u - 1].push_back(v - 1);
			if (d == 2)
				g[v - 1].push_back(u - 1);
		}
		// Initialize all global variables
		dfs_num.assign(n, UNVISITED);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		dfs_counter = num_scc = 0;
		// Find all strongly connected components
		for (int i = 0; i != n; ++i)
			if (dfs_num[i] == UNVISITED)
				tarjanSCC(i);
		printf("%d\n", num_scc == 1 ? 1 : 0);
	}
	return 0;
}
