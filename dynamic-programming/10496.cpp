#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef pair<int, int> ii;

const int maxn = 15;
int size_x, size_y, nP;			// nP is the number of places including the starting point
ii poses[maxn];					// positions for all places
int dist[maxn][maxn];			// distance between all places
int memo[maxn][1 << maxn];		// memoization table


int cal_dis(const ii& pos1, const ii& pos2)
{
	return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

// Top-down dynamic programming function to calculate the minimum travel distance from id after having seen "visited" place back to start
int tsp(int id, int visited)
{
	if (visited == (1 << nP) - 1)		// have visited all places
		return dist[id][0];
	if (memo[id][visited] != -1)		// have calculated this state before
		return memo[id][visited];
	int ans = 1000000001;
	for (int i = 0; i != nP; ++i)
	{
		if (!(visited & (1 << i)))		// try every non-visited place
		{
			ans = min(ans, dist[id][i] + tsp(i, visited | (1 << i)));
		}
	}
	return memo[id][visited] = ans;
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
		scanf("%d %d", &size_x, &size_y);
		scanf("%d %d", &poses[0].first, &poses[0].second);
		scanf("%d", &nP);
		++nP;
		for (int i = 1; i != nP; ++i)
			scanf("%d %d", &poses[i].first, &poses[i].second);
		memset(dist, 0, sizeof(dist));
		for (int i = 0; i != nP; ++i)
			for (int j = 0; j != nP; ++j)
				dist[i][j] = cal_dis(poses[i], poses[j]);
		memset(memo, -1, sizeof(memo));
		int ans = tsp(0, 1);
		printf("The shortest path has length %d\n", ans);
	}
	return 0;
}
