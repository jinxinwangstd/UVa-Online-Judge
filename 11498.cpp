#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int k;
	while (scanf("%d", &k) == 1 && k)
	{
		int n, m;					// the coordinates of division point
		scanf("%d %d", &n, &m);
		while (k--)
		{
			int x, y;				// the coordinates of test case point
			scanf("%d%d", &x, &y);
			if (x == n || y == m)
				cout << "divisa";
			else
			{
				if (y > m)			// determine the N-S side
					cout << "N";
				else
					cout << "S";
				if (x > n)			// determine the W-E side
					cout << "E";
				else
					cout << "O";
			}
			cout << '\n';
		}
	}
	return 0;
}
