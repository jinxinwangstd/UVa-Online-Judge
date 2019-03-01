#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int t, caseNo = 1;
	scanf("%d", &t);
	while (caseNo <= t)
	{
		int n;
		scanf("%d", &n);
		int speeds[n], i;
		for (i = 0; i != n; ++i)	// read in all the speeds of scary creatures
			scanf("%d", &speeds[i]);
		sort(speeds, speeds + n);
		printf("Case %d: %d\n", caseNo++, speeds[n - 1]);
	}
	return 0;
}
