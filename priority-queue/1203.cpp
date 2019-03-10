#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 100;

struct Task
{
	int id;
	int period;			// interval between two times of returning values
	int exe_time;		// the time of returning value
	Task(int id, int period, int exe_time): id(id), period(period), exe_time(exe_time) {};
};

// Compare two query to determine which one to return first
class Compare
{
public:
	bool operator() (const Task& a, const Task& b)
	{
		if (a.exe_time != b.exe_time)
			return a.exe_time > b.exe_time;
		else
			return a.id > b.id;
	}
};

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	char buffer[maxn];
	priority_queue<Task, vector<Task>, Compare> schedule;
	while (scanf("%s", buffer) && buffer[0] != '#')
	{
		int id, period;
		scanf("%d%d", &id, &period);
		getchar();
		Task new_task(id, period, period);
		schedule.push(new_task);
	}
	int N;
	scanf("%d", &N);
	while (N--)
	{
		Task query = schedule.top();	// Get the next query
		schedule.pop();
		printf("%d\n", query.id);
		// Schedule the next query for the same service
		Task next_task(query.id, query.period, query.period + query.exe_time);
		schedule.push(next_task);
	}
	return 0;
}
