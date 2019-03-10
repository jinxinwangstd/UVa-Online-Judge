#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 3000 + 50;
bitset<maxn> record;			// record the appearance of different values of absolute difference between successive elements

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) == 1)
	{
		record.reset();
		if (n == 1)
		{
			scanf("%d", &n);
			printf("Jolly\n");
			continue;
		}
		int num1, num2;					// num2 is the successive element after num1
		scanf("%d", &num1);
		int i;
		for (i = 0; i != n - 1; ++i)
		{
			scanf("%d", &num2);
			if (abs(num2 - num1) < n)	// the difference is within the range [0, n)
				record.set(abs(num2 - num1));
			num1 = num2;
		}
		bool j_flag = true;
		for (i = 1; i != n; ++i)		// Check whether all values in [1, n-1] are present
			if (!record[i])
				j_flag = false;
		printf("%s\n", j_flag ? "Jolly" : "Not jolly");
	}
	return 0;
}
