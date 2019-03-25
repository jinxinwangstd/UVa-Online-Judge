#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 1000 + 50;
const int maxW = 30 + 5;
int V[maxn], W[maxn], n;
int memo[maxn][maxW];			// memoization table

// Top-down recursive function to find maximum value buying goods from id to n-1 with remW weight
int value(int id, int remW)
{
	if (id == n)		// base case: has considered all goods
		return 0;
	if (remW == 0)		// base case: no remaining weight
		return 0;
	if (memo[id][remW] != -1)	// has visited this state before
		return memo[id][remW];
	// Recurrence relation
	if (remW < W[id])
		return memo[id][remW] = value(id + 1, remW);
	else
		return memo[id][remW] = max(value(id + 1, remW), V[id] + value(id + 1, remW - W[id]));
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
		memset(memo, -1, sizeof(memo));		// reset the memoization table to a special value
		scanf("%d", &n);
		for (int i = 0; i != n; ++i)
			scanf("%d %d", &V[i], &W[i]);
		int nG, gW, ans = 0;
		scanf("%d", &nG);
		while (nG--)
		{
			scanf("%d", &gW);
			ans += value(0, gW);
		}
		printf("%d\n", ans);
	}
	return 0;
}
