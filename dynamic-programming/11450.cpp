#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

int M, C;
int price[25][25];	// storing the number of models for each garment and their prices
int memo[210][25];	// dp table memo storing the solution for each possible state
// Return the maximum amount of money we can spend for a specific state (Top-Down DP solution)
int shop(int money, int g)
{
	if (money < 0)				// fail, return a large -ve number
		return -1000000000;
	if (g == C)					// the solution is finished
		return M - money;
	if (memo[money][g] != -1)	// memoization
		return memo[money][g];
	int ans = -1;	// start with a -ve number (not possible answer)
	for (int model = 1; model <= price[g][0]; ++model)
		ans = max(ans, shop(money - price[g][model], g + 1));
	return memo[money][g] = ans;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int i, j, N, score;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d %d", &M, &C);
		for (i = 0; i != C; ++i)
		{
			scanf("%d", &price[i][0]);
			for (j = 1; j <= price[i][0]; ++j)
				scanf("%d", &price[i][j]);
		}
		memset(memo, -1, sizeof(memo));
		score = shop(M, 0);			// use DP to crack this problem
		if (score < 0)
			printf("no solution\n");
		else
			printf("%d\n", score);
	}
	return 0;
}
