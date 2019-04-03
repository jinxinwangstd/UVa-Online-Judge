#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int maxn = 100 + 5;
int g[maxn][maxn];			// graph represented by adjacent matrix
int reachable[maxn];		// record whether every node is reachable from start in the original graph
int dfs_num[maxn];			// dfs array to avoid cycle
int n, id;

void dfs(int u)
{
	if (u == id)		// equivalent to removing all outcoming edges of node "id"
		return;
	dfs_num[u] = 1;
	for (int i = 0; i != n; ++i)
	{
		if (g[u][i] && !dfs_num[i])
			dfs(i);
	}
}

// Print one line of frame of the output like that
// +------------------------+
void printEdge()
{
	printf("+");
	for (int i = 1; i != 2 * n; ++i)
		printf("-");
	printf("+\n");
	return;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int nT, caseNo = 0;
	scanf("%d", &nT);
	while (nT--)
	{
		printf("Case %d:\n", ++caseNo);
		scanf("%d", &n);
		for (int i = 0; i != n; ++i)
			for (int j = 0; j != n; ++j)
				scanf("%d", &g[i][j]);
		memset(dfs_num, 0, sizeof(dfs_num));
		id = -1;		// at first not removing any edge
		dfs(0);
		for (int i = 0; i != n; ++i)	// test the reachability from the root node
			reachable[i] = dfs_num[i];
		printEdge();
		for (id = 0; id != n; ++id)
		{
			memset(dfs_num, 0, sizeof(dfs_num));
			dfs(0);
			printf("|");
			for (int i = 0; i != n; ++i)
				printf("%s|", reachable[i] && !dfs_num[i] ? "Y" : "N");		// only the node that is originally reachable and after removing one node became unreachable is dominated
			printf("\n");
			printEdge();
		}
	}
	return 0;
}
