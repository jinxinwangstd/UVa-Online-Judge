#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxm = 7500;
const int num_change = 5;
const int change[num_change] = {50, 25, 10, 5, 1};
ll memo[num_change][maxm];			// not necessary, but in case of integer overflow

// Top-down dynamic programming function to calculate the total ways to make change for remM money with coins from idth to n-1th
int make_change(int id, int remM)
{
	if (remM == 0)					// there is only one way to make change for zero money
		return 1;
	if (id == num_change - 1)		// there is only one way to make change with 1 cent, which is make them all 1 cents
		return 1;
	if (memo[id][remM] != -1)		// have calculated this state
		return memo[id][remM];
	if (change[id] > remM)			// the coin is too much for remaining money
		return memo[id][remM] = make_change(id + 1, remM);
	else
	{
		ll ans = 0;
		for (int i = 0; i <= remM / change[id]; ++i)	// can have this coin in number of 0 to maximum possible
			ans += make_change(id + 1, remM - i * change[id]);
		return memo[id][remM] = ans;
	}
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	memset(memo, -1, sizeof(memo));
	int amount;
	while (scanf("%d", &amount) != EOF)
		printf("%d\n", make_change(0, amount));
	return 0;
}
