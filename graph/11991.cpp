#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef int pos;
typedef vector<pos> occurrences;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		map<int, occurrences> seq;		// storing every appeared integer and its appearing positions
		for (int i = 1; i <= n; ++i)
		{
			int num;
			scanf("%d", &num);
			seq[num].push_back(i);
		}
		int k, v;
		while (m--)
		{
			scanf("%d %d", &k, &v);
			if (!seq.count(v) || seq[v].size() < k)		// such appearing does not exist
				printf("0\n");
			else
				printf("%d\n", seq[v][k - 1]);
		}
	}
	return 0;
}
