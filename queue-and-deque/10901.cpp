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
		memset(arr_times, 0, sizeof(arr_times));	// not necessary because each test case we will overwrite the arriving time
		queue<ii> lb, rb, ferry;
		string buffer;
		for (int i = 0; i != m; ++i)
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
		int time = 0, side = 0;		// the 0 value of side means our ferry is in the left bank
		while (!lb.empty() || !rb.empty())
		{
			if (side)		// ferry is at the right bank
			{
				while (!rb.empty() && rb.front().second <= time && (int) ferry.size() < n)
				{
					ferry.push(rb.front());
					rb.pop();
				}
			}
			else			// ferry is at the left bank
			{
				while (!lb.empty() && lb.front().second <= time && (int) ferry.size() < n)
				{
					ferry.push(lb.front());
					lb.pop();
				}
			}
			if (ferry.empty())	// there is no car on the side of ferry currently
			{
				ii next_car;
				int next_car_side = -1;
				if (lb.empty())			// the left bank has no car to arrive
				{
					next_car = rb.front();
					next_car_side = 1;
				}
				else if (rb.empty())	// the right bank has no car to arrive
				{
					next_car = lb.front();
					next_car_side = 0;
				}
				else					// determine cars in which bank arrive first
				{
					if (lb.front().second == rb.front().second)
						next_car = side ? rb.front() : lb.front();
					else
						next_car = lb.front().second < rb.front().second ? lb.front() : rb.front();
					next_car_side = lb.front().second == rb.front().second ? side : lb.front().second > rb.front().second;
				}
				if (next_car.second <= time)	// the car already arrives, so it must be in the other side
				{
					side = !side;
					time += t;
				}
				else							// the car has not arrived yet
				{
					time = next_car.second;
					time += (side == next_car_side ? 0 : t);
					side = next_car_side;
				}
				continue;
			}
			time += t;
			side = !side;
			while (!ferry.empty())				// unload cars on the ferry
			{
				arr_times[ferry.front().first] = time;
				ferry.pop();
			}
		}
		for (int i = 0; i != m; ++i)
			printf("%d\n", *(arr_times + i));
		if (nt)
			printf("\n");
	}
	return 0;
}
