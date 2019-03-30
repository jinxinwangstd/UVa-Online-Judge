#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 50 + 5;
int cps[maxn], n, l, memo[maxn][maxn];

// Top-down dynamic programming function to calculate the minimum cost to cut a stick through all cutting points
int minCut(int left, int right)
{
	if (right - left == 1)					// no cutting points in the stick
		return 0;
	if (memo[left][right] != -1)			// having visited this state
		return memo[left][right];
	int ans = INT_MAX;
	for (int i = left + 1; i != right; ++i)	// trying all cutting points and select the one with minimum cost
		ans = min(ans, minCut(left, i) + minCut(i, right) + cps[right] - cps[left]);
	return memo[left][right] = ans;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d", &l) && l)
	{
		memset(memo, -1, sizeof(memo));
		scanf("%d", &n);
		cps[0] = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%d", &cps[i]);
		cps[n + 1] = l;
		n += 2;
		printf("The minimum cutting is %d.\n", minCut(0, n - 1));
	}
	return 0;
}
