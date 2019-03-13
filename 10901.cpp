#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef pair<int, int> ii;

const int maxn = 10000 + 50;
int arr_times[maxn];

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int nt;
	scanf("%d", &nt);
	while (nt--)
	{
		int n, t, m;
		scanf("%d %d %d", &n, &t, &m);
		getchar();
		memset(arr_times, 0, sizeof(arr_times));
		queue<ii> lb, rb;
		string buffer;
		for (int i = 0; i != m; i++)
		{
			getline(cin, buffer);
			int time;
			string side;
			stringstream ss(buffer);
			ss >> time >> side;
			if (side[0] == 'l')
				lb.push(make_pair(i, time));
			else
				rb.push(make_pair(i, time));
		}
		int time = 0, side = 0, load = 0;
		while (!lb.empty() || !rb.empty())
		{
			if (side)		// ferry is at the right bank
			{
				while (!rb.empty() && rb.front() <= time && load < n)
				{
					rb.pop();
					load++;
				}
			}
			else			// ferry is at the left bank
			{
				while (!lb.empty() && lb.front() <= time && load < n)
				{
					lb.pop();
					load++;
				}
			}
			if (!load)
			{
				int next_car = -1, next_car_side = -1;
				if (lb.empty())
				{
					next_car = rb.front();
					next_car_side = 1;
				}
				else if (rb.empty())
				{
					next_car = lb.front();
					next_car_side = 0;
				}
				else
				{
					next_car = min(lb.front(), rb.front());
					next_car_side = lb.front() == rb.front() ? side : lb.front() > rb.front();
				}
				if (next_car <= time)
				{
					side = !side;
					time += t;
				}
				else
				{
					time = next_car;
					time += (side == next_car_side ? 0 : 10);
					side = next_car_side;
				}
				continue;
			}
			time += t;
			side = !side;
			while (load)
			{
				printf("%d\n", time);
				--load;
			}
		}
		if (nt)
			printf("\n");
	}
	return 0;
}
