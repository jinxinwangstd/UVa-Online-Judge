#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef pair<double, double> dd;
typedef vector<dd> vdd;

// Compare sprinklers (intervals) according to increasing left boundaries and decreasing right boundaries
bool compare(const dd& a, const dd& b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n, l, w;
	while (scanf("%d %d %d", &n, &l, &w) != EOF)
	{
		vdd sprinklers;
		int p, r;
		for (int i = 0; i != n; ++i)
		{
			scanf("%d %d", &p, &r);
			if (r < ((double) w / 2))	// the sprinkler whose diameter is smaller than the width of the strip cannot be used
				continue;
			double dp = sqrt(pow(r, 2) - pow((double) w / 2, 2));	// use pow() to calculate the exponents in case of integer overflow
			dd s = make_pair(p - dp, p + dp);
			sprinklers.push_back(s);
		}
		sort(sprinklers.begin(), sprinklers.end(), compare);
		int ret = 0;				// number of sprinklers we used
		double covered_p = 0.0;		// the right-most position covered by sprinklers
		int s_i = 0;
		bool fully_covered = true;
		while (covered_p < l)
		{
			double new_covered_p = covered_p;
			while (s_i < (int) sprinklers.size() && sprinklers[s_i].first <= covered_p)	// check boundaries of referred array!!!
			{
				if (sprinklers[s_i].second > new_covered_p)
					new_covered_p = sprinklers[s_i].second;
				++s_i;
			}
			if (new_covered_p == covered_p)		// there is no sprinkler which can cover more strips
			{
				fully_covered = false;
				break;
			}
			else
				++ret;
			covered_p = new_covered_p;
		}
		printf("%d\n", fully_covered ? ret : -1);
	}
	return 0;
}
