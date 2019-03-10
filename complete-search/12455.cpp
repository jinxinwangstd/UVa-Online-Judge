#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, p;
		scanf("%d %d", &n, &p);
		int bars[p];
		for (int i = 0; i != p; ++i)
			scanf("%d", bars + i);
		bool solved = false;
		// generate all subsets of bars
		for (int i = 0; i != (1 << p); ++i)
		{
			int sum = 0;
			for (int j = 0; j != p; ++j)
			{
				if (i & (1 << j))
					sum += bars[j];
			}
			// check whether the sum of this subset is equal to the given parameter
			if (sum == n)
			{
				printf("YES\n");
				solved = true;
				break;
			}
		}
		if (!solved)
			printf("NO\n");
	}
	return 0;
}
