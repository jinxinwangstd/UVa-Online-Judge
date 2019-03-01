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
	int size;
	ll p;		// the max value of p is larger than int object, so use int64_t
	while (scanf("%d %ld", &size, &p) == 2 && size && p)
	{
		int l = (size + 1) / 2;
		int c = l;
		int minc = c - 1, maxc = c + 1, minl = l - 1, maxl = l + 1;		// track the min and max value of row and column indexs for each square layer
		ll end = 1;			// To avoid integer overflow
		// Determine which square layer that p belongs to
		while (p >= (end + 2) * (end + 2))
		{
			++l;
			++c;
			end += 2;
			--minl;
			--minc;
			++maxl;
			++maxc;
		}
		if (p == end * end)
		{
			printf("Line = %d, column = %d.\n", l, c);
			continue;
		}
		ll n = end * end + 1;	// To avoid integer overflow
		++l;
		// Traverse through the square layer in the direction where spiral index increments
		while (p != n)
		{
			if (c != minc && l == maxl)			// upper path
			{
				++n;
				--c;
			}
			else if (c == minc && l != minl)	// left path
			{
				++n;
				--l;
			}
			else if (c != maxc && l == minl)	// lower path
			{
				++n;
				++c;
			}
			else								// right path
			{
				++n;
				++l;
			}
		}
		printf("Line = %d, column = %d.\n", l, c);
	}
	return 0;
}
