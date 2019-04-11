#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int maxn = 100 + 5;
int g[maxn][maxn];

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int nT, caseNo = 0;
	scanf("%d", &nT);
	int n, m;
	while (nT--)
	{
		printf("Case %d: ", ++caseNo);
		scanf("%d %d", &n, &m);
		// Initialize the graph. Note that memset is not working here, so that we must write explicit loops
		for (int i = 0; i != n; ++i)
			for (int j = 0; j != n; ++j)
				g[i][j] = i == j ? 0 : INT_MAX / 2;		// no self-loop so that distance between vertex and itself is 0; distance between two different vertices is INF because there are no edges yet.
		// Read in edges
		int u, v;
		for (int i = 0; i != m; ++i)
		{
			scanf("%d %d", &u, &v);
			g[u][v] = g[v][u] = 1;
		}
		// Floyd Warshall's algorithm to calculate the shortest distance between all pairs of vertices
		for (int k = 0; k != n; ++k)
			for (int i = 0; i != n; ++i)
				for (int j = 0; j != n; ++j)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		// Find the longest distance between q1 and q2
		int q1, q2, ret = 0;
		scanf("%d %d", &q1, &q2);
		for (int i = 0; i != n; ++i)
			ret = max(ret, g[q1][i] + g[i][q2]);
		printf("%d\n", ret);
	}
	return 0;
}
