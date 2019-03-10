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
	int n;
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		string buffer;
		stack<int> s;
		queue<int> q;
		priority_queue<int> p;
		bool s_flag = true, q_flag = true, p_flag = true;
		while (n--)
		{
			getline(cin, buffer);
			stringstream ss(buffer);
			int type, argument;
			ss >> type >> argument;
			if (type == 1)			// push operations
			{
				if (s_flag)
					s.push(argument);
				if (q_flag)
					q.push(argument);
				if (p_flag)
					p.push(argument);
			}
			else					// pop operations
			{
				if (s_flag)
				{
					if (s.empty())	// check whether pop operation is valid
						s_flag = false;
					else
					{
						s_flag = s.top() == argument;
						s.pop();
					}
				}
				if (q_flag)
				{
					if (q.empty())	// check whether pop operation is valid
						q_flag = false;
					else
					{
						q_flag = q.front() == argument;
						q.pop();
					}
				}
				if (p_flag)
				{
					if (p.empty())	// check whether pop operation is valid
						p_flag = false;
					else
					{
						p_flag = p.top() == argument;
						p.pop();
					}
				}
			}
		}
		if (!s_flag && !q_flag && !p_flag)
			printf("impossible\n");
		else if (s_flag && !q_flag && !p_flag)
			printf("stack\n");
		else if (!s_flag && q_flag && !p_flag)
			printf("queue\n");
		else if (!s_flag && !q_flag && p_flag)
			printf("priority queue\n");
		else
			printf("not sure\n");
	}
	return 0;
}
