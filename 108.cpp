#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 100;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int a[n][n];		// 2D array storing sum of sub-rectangle from (0,0) to (i,j)
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
		{
			scanf("%d", &a[i][j]);
			// Pre-computation trick
			if (i > 0)						// if possible, add from top
				a[i][j] += a[i - 1][j];
			if (j > 0)						// if possible, add from left
				a[i][j] += a[i][j - 1];
			if (i > 0 && j > 0)				// avoid double count
				a[i][j] -= a[i - 1][j - 1];
		}
	int ans = -127 * maxn * maxn;		// the lowest possible value for a sum of sub-rectangle
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != n; ++j)
			for (int k = i; k != n; ++k)
				for (int l = j; l != n; ++l)
				{
					int sum = a[k][l];
					if (i > 0)				// exclude the top extra
						sum -= a[i - 1][l];
					if (j > 0)				// exclude the left extra
						sum -= a[k][j - 1];
					if (i > 0 && j > 0)		// avoid double count
						sum += a[i - 1][j - 1];
					ans = max(sum, ans);	// update the answer
				}
	printf("%d\n", ans);
	return 0;
}
