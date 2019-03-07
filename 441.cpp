#include <bits/stdc++.h>

using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int size = 6;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int k, caseNo = 0;
	while (scanf("%d", &k) && k)
	{
		++caseNo;
		printf("%s", caseNo == 1 ? "" : "\n");
		int seq[k];
		for (int i = 0; i != k; ++i)
			scanf("%d", seq + i);
		// Enumerate all subsets of size 6 of the set seq
		for (int a = 0; a <= k - size; ++a)
			for (int b = a + 1; b <= k - (size - 1); ++b)
				for (int c = b + 1; c <= k - (size - 2); ++c)
					for (int d = c + 1; d <= k - (size - 3); ++d)
						for (int e = d + 1; e <= k - (size - 4); ++e)
							for (int f = e + 1; f <= k - (size - 5); ++f)
								printf("%d %d %d %d %d %d\n", seq[a], seq[b], seq[c], seq[d], seq[e], seq[f]);
	}
	return 0;
}
