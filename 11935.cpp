#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const double eps = 1e-9;
vector<string> events;

// determine whether the car could arrive the end
bool arrive(double f)
{
	int prev_pos = 0;	// the position of last event
	int now_pos = 0;	// the position of current event
	double consume_rate = 0.0;	// driving fuel consumption, stored as litres per kilometer
	int num_leaks = 0;	// every leak results in one litre fuel consumption per kilometer
	double left_fuel = f;
	int num_events = events.size();
	string event;
	int parameter;
	for (int i = 0; i != num_events; ++i)
	{
		stringstream ss(events[i]);
		ss >> now_pos;
		ss >> event;
		left_fuel -= (consume_rate + num_leaks) * (now_pos - prev_pos);		// calculate the left fuel right before the car arrives this event
		if (left_fuel < 0)			// no enough fuel to arrive this event
			break;
		if (event[0] == 'F')		// change fuel consumption rate while normally driving
		{
			ss >> event;
			ss >> parameter;
			consume_rate = (double) parameter / 100;
		}
		else if (event[0] == 'L')	// adding a leak on the tank
			num_leaks++;
		else if (event[0] == 'M')	// repairing all leaks
			num_leaks = 0;
		else if (event[0] == 'G' && i != num_events - 1)	// refuel the tank to full
			left_fuel = f;
		else						// reach the end
			;
		prev_pos = now_pos;
	}
	return left_fuel >= 0;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	string buffer;
	getline(cin, buffer);
	while (true)
	{
		stringstream ss(buffer);
		string event;
		int n;
		ss >> n >> event >> event >> n;
		if (!n)
			break;
		events.clear();
		events.push_back(buffer);
		while (getline(cin, buffer) && !(buffer[0] == '0' && buffer[2] == 'F'))
			events.push_back(buffer);
		double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;
		// binary search the minimum fuel capacity that meets requirements
		while (fabs(hi - lo) > eps)		// when the answer is not found yet
		{
			mid = (lo + hi) / 2.0;
			if (arrive(mid))	// be able to arrive the end
			{
				ans = mid;
				hi = mid;
			}
			else				// not enough fuel
				lo = mid;
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
