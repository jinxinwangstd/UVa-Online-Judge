#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n, b, h, w;
	while (scanf("%d%d%d%d", &n, &b, &h, &w) == 4)
	{
		int price, capacity, ret = 0;
		while (h--)
		{
			scanf("%d", &price);
			int i = 0, a;
			capacity = 0;
			for (i = 0; i != w; ++i)		// find the maximum capacity for every available weekend
			{
				scanf("%d", &a);
				capacity = a > capacity ? a : capacity;
			}
			if (capacity >= n && (n * price) <= b)
			{
				if (ret)					// if this is not the first satisfying hotel, we need to check whether it is lower than our chosen one
					ret = ret > (n * price) ? n * price : ret;
				else						// this is the first satisfying hotel
					ret = n * price;
			}
		}
		if (ret)
			printf("%d\n", ret);
		else
			printf("stay home\n");
	}
	return 0;
}
