#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef pair<double, double> dd;
typedef vector<dd> vdd;

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
		while (n--)
		{
			scanf("%d %d", &p, &r);
			double dp = sqrt(r * r - ((double) w / 2) * ((double) w / 2));
			dd s = make_pair(p - dp, p + dp);
			sprinklers.push_back(s);
		}
		//printf("continue\n");
		sort(sprinklers.begin(), sprinklers.end(), compare);
		int ret = 0;
		double covered_p = 0.0;
		int s_i = 0;
		bool fully_covered = true;
		while (covered_p < l)
		{
			double new_covered_p = covered_p;
			while (sprinklers[s_i].first <= covered_p)
			{
				if (sprinklers[s_i].second > new_covered_p)
					new_covered_p = sprinklers[s_i].second;
				++s_i;
			}
			if (new_covered_p == covered_p)
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
