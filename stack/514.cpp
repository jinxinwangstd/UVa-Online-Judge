#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 1000 + 5;
int B[maxn];

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		while (scanf("%d", &B[0]) == 1)
		{
			if (!B[0])
				break;
			for (int i = 1; i != N; ++i)
				scanf("%d", &B[i]);
			stack<int> station;
			int B_i = 0, i = 1;
			while (B_i < N)
			{
				if (B[B_i] == i)
				{
					++B_i;
					++i;
				}
				else if (!station.empty() && B[B_i] == station.top())	// first check whether stack is empty or not when accessing a stack
				{
					station.pop();
					++B_i;
				}
				else if (i <= N)
				{
					station.push(i);
					++i;
				}
				else
				{
					printf("No\n");
					break;
				}
			}
			if (B_i == N)
				printf("Yes\n");
		}
		printf("\n");
	}
	return 0;
}
