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
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		set<int> ncds;
		// Read in the elements in n's group
		for (int i = 0; i != n; ++i)
		{
			int cd = 0;
			scanf("%d", &cd);
			ncds.insert(cd);
		}
		int mcd, m_i = 1;
		scanf("%d", &mcd);
		int ret = 0;
		// Compare the elements in n's group and m's group
		for (set<int>::iterator iter = ncds.begin(); iter != ncds.end(); ++iter)
		{
			while (m_i < m && mcd < *iter)
			{
				scanf("%d", &mcd);
				++m_i;
			}
			if (mcd == *iter)
				++ret;
		}
		// Consume the left input lines
		if (m_i < m)
		{
			for (int i = 0; i != m - m_i; ++i)
				scanf("%d", &mcd);
		}
		printf("%d\n", ret);
	}
	return 0;
}
