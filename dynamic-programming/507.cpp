#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 20000 + 50;
int segs[maxn];

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int nT = 0;
	scanf("%d", &nT);
	for (int r = 1; r <= nT; ++r)
	{
		int n = 0;
		scanf("%d", &n);
		for (int i = 0; i < n - 1; ++i)
			scanf("%d", segs + i);
		int sum = 0, ans = 0;		// sum is the sum of currently scanning sequence, ans is the maximum range sum query
		int ans_i = 0, ans_j = 0;	// start and end stops for the final answer
		int start = 0, end = 0;		// start and end stops for the currently scanning sequence
		for (int i = 0; i < n - 1; ++i)
		{
			sum += segs[i];
			end = i;
			if (sum > ans)			// record the new maximum range sum
			{
				ans_i = start;
				ans_j = end;
			}
			else if (sum == ans)	// tie in maximum range sum
			{
				if (end - start > ans_j - ans_i)	// only record the current sequence if it is longer
				{
					ans_i = start;
					ans_j = end;
				}
			}
			else if (sum < 0)		// restart sequence from the next element
			{
				sum = 0;
				start = i + 1;		// here is i + 1 because we start from next element
				end = start;
			}
			ans = max(ans, sum);	// update the maximum range sum
		}
		if (ans)
			printf("The nicest part of route %d is between stops %d and %d\n", r, ans_i + 1, ans_j + 2);
		else
			printf("Route %d has no nice parts\n", r);
	}
	return 0;
}
