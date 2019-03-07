#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 3;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && (n || m))
	{
		int p[n];
		for (int i = 0; i != n; ++i)
			p[i] = i;
		vector<vector<int> > constraints;
		for (int i = 0; i != m; ++i)
		{
			vector<int> constraint;
			for (int j = 0; j != maxn; ++j)
			{
				int num;
				scanf("%d", &num);
				constraint.push_back(num);
			}
			constraints.push_back(constraint);
		}
		int ret = 0;
		do
		{
			bool satisfy = true;
			for (int i = 0; i != m; ++i)
			{
				int *p1 = find(p, p + n, constraints[i][0]);
				int *p2 = find(p, p + n, constraints[i][1]);
				int c = constraints[i][2];
				if (c > 0 && abs(p1 - p2) > c)
				{
					satisfy = false;
					break;
				}
				else if (c < 0 && abs(p1 - p2) < abs(c))
				{
					satisfy = false;
					break;
				}
			}
			if (satisfy)
				++ret;
		}
		while (next_permutation(p, p + n));
		printf("%d\n", ret);
	}
	return 0;
}
