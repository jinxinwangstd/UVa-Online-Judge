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
	int set;
	scanf("%d", &set);
	while (set--)
	{
		int n, s, q;
		scanf("%d %d %d", &n, &s, &q);
		vector<queue<int> > stations;
		stack<int> carrier;
		int non_empty = n;
		for (int i = 0; i != n; ++i)
		{
			int num;
			scanf("%d", &num);
			if (!num)
				--non_empty;
			queue<int> station;
			while (num--)
			{
				int cargo;
				scanf("%d", &cargo);
				station.push(cargo);
			}
			stations.push_back(station);
		}
		int s_i = 0, ret = 0;
		while (non_empty || !carrier.empty())
		{
			if (stations[s_i].empty())
				++non_empty;
			while (!carrier.empty() && ((int) stations[s_i].size() < q || ((int) stations[s_i].size() == q && carrier.top() == s_i + 1)))
			{
				int cargo = carrier.top();
				carrier.pop();
				++ret;
				if (cargo != s_i + 1)
					stations[s_i].push(cargo);
			}
			while (!stations[s_i].empty() && (int) carrier.size() < s)
			{
				int cargo = stations[s_i].front();
				stations[s_i].pop();
				++ret;
				carrier.push(cargo);
			}
			if (stations[s_i].empty())
				--non_empty;
			s_i = s_i + 1 == n ? 0 : s_i + 1;
			ret += 2;
		}
		ret -= 2;
		printf("%d\n", ret);
	}
	return 0;
}
