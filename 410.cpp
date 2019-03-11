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
	int c, s, caseNo = 0;
	while (scanf("%d %d", &c, &s) != EOF)
	{
		caseNo++;
		printf("Set #%d\n", caseNo);
		vector<int> specimens;
		int i = 0;
		// Read in all specimens to be assigned
		for (; i != s; ++i)
		{
			int specimen;
			scanf("%d", &specimen);
			specimens.push_back(specimen);
		}
		// Supply dummy specimens (0 mass) to enlarge the vector into the size of 2c, so that every chamber would have 2 specimens
		for (; i != 2 * c; ++i)
			specimens.push_back(0);
		sort(specimens.begin(), specimens.end());
		int chambers[c];
		memset(chambers, 0, sizeof(chambers));
		double ret = 0.0, am = accumulate(specimens.begin(), specimens.end(), 0.0) / c;		// average mass
		for (i = 0; i != c; ++i)
		{
			printf(" %d:", i);
			// For a chamber whose index is k, we assign the kth largest and kth smallest specimens to it
			int s_i = i;
			if (specimens[s_i])
				printf(" %d", specimens[s_i]);
			chambers[i] += specimens[s_i];
			s_i = 2 * c - 1 - s_i;
			if (specimens[s_i])
				printf(" %d", specimens[s_i]);
			chambers[i] += specimens[s_i];
			ret += fabs(chambers[i] - am);		// standard deviation
			printf("\n");
		}
		printf("IMBALANCE = %.5lf\n\n", ret);
	}
	return 0;
}
