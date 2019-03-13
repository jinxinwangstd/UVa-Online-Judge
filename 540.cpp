#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

//const int maxn = 1000000 + 50;
//int ids[maxn];

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
		map<int, int> ids;
		vector<queue<int> > teams;
		queue<int> q;
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
			if (type[0] == 'E')
			{
				int x, x_id;
				ss >> x;
				x_id = ids[x];
				if (teams[x_id].empty())
					q.push(x_id);
				teams[x_id].push(x);
			}
			else
			{
				int front_id = q.front();
				printf("%d\n", teams[front_id].front());
				teams[front_id].pop();
				if (teams[front_id].empty())
					q.pop();
			}
		}
		printf("\n");
	}
	return 0;
}
