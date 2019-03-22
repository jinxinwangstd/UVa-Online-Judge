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
	int n, caseNo = 0;
	while (scanf("%d", &n) && n)
	{
		++caseNo;
		printf("Scenario #%d\n", caseNo);
		map<int, int> ids;			// record each element's team id
		vector<queue<int> > teams;	// record each team's queue
		queue<int> q;				// record the team queue
		for (int i = 0; i != n; ++i)
		{
			int num_elem;
			scanf("%d", &num_elem);
			queue<int> team;
			teams.push_back(team);
			while (num_elem--)
			{
				int elem;
				scanf("%d", &elem);
				ids[elem] = i;
			}
		}
		getchar();
		string cmd;
		while (getline(cin, cmd) && cmd[0] != 'S')
		{
			stringstream ss(cmd);
			string type;
			ss >> type;
			if (type[0] == 'E')				// an element enqueue
			{
				int x, x_id;
				ss >> x;
				x_id = ids[x];
				if (teams[x_id].empty())	// if it is the first element in his team
					q.push(x_id);
				teams[x_id].push(x);
			}
			else 							// dequeue from the team queue
			{
				if (!q.empty())				// check whether there are elements in the queue
				{
					int front_id = q.front();
					printf("%d\n", teams[front_id].front());
					teams[front_id].pop();
					if (teams[front_id].empty())	// if the team has all elements dequeued
						q.pop();
				}
				// else we output nothing
			}
		}
		printf("\n");
	}
	return 0;
}
