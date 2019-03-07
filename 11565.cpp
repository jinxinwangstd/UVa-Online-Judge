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
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int upper = floor(sqrt((double) c));
		int lower = ceil(-sqrt((double) c));
		bool solved = false;
		for (int x = lower; x <= upper; ++x)
		{
			for (int y = lower; y <= upper; ++y)
			{
				for (int z = lower; z <= upper; ++z)
				{
					if (x == y || y == z || x == z)
						continue;
					if (x + y + z != a)
						continue;
					if (x * y * z != b)
						continue;
					if (x * x + y * y + z * z != c)
						continue;
					solved = true;
					printf("%d %d %d\n", x, y, z);
					break;
				}
				if (solved)
					break;
			}
			if (solved)
				break;
		}
		if (!solved)
			printf("No solution.\n");
	}
	return 0;
}
