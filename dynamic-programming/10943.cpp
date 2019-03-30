#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 105;
int n, k, memo[maxn][maxn];

// Top-down dynamic programming function to calculate the number of ways to adding "num" numbers result in a number equal to "rem"
int addWays(int num, int rem)
{
	if (num == 1)		// if there is only one number left, let it be the rem, which is a valid adding way
		return 1;
	if (rem == 0)		// if rem = 0, let all left numbers be 0, which is also a valid adding way
		return 1;
	if (memo[num][rem] != 0)	// if the state has been visited before
		return memo[num][rem];
	int ans = 0;
	for (int i = 0; i <= rem; ++i)	// the next adding number could be any num from 0 to rem
	{
		ans += addWays(num - 1, rem - i);
		ans %= 1000000;		// the result should be modulo of 1000000
	}
	return memo[num][rem] = ans;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	memset(memo, 0, sizeof(memo));
	while (scanf("%d %d", &n, &k) == 2 && n && k)
		printf("%d\n", addWays(k, n));
	return 0;
}
