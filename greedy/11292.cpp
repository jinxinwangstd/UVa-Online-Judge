#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 20000 + 50;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && (n || m))
	{
		int dhs[maxn];
		int ks[maxn];
		for (int i = 0; i != n; ++i)
			scanf("%d", dhs + i);
		for (int i = 0; i != m; ++i)
			scanf("%d", ks + i);
		sort(dhs, dhs + n);
		sort(ks, ks + m);
		int dh_i = 0, k_i = 0;
		ll cost = 0;
		while (k_i != m && dh_i != n)	// still have dragon heads or knights
		{
			if (ks[k_i] >= dhs[dh_i])	// this is the lowest knight who can chop off the corresponding dragon head
			{
				cost += ks[k_i];
				++dh_i;
			}
			++k_i;
		}
		if (dh_i != n)		// still have dragon heads not chopped off
			printf("Loowater is doomed!\n");
		else				// all killed
			printf("%ld\n", cost);
	}
	return 0;
}
