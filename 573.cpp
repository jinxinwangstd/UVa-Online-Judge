#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int h, u, d, f_per;
	while (scanf("%d%d%d%d", &h, &u, &d, &f_per) == 4 && h)
	{
		double height = (double) h;
		double climb_dis = (double) u;
		double slide_dis = (double) d;
		double fatique_dis = (double) f_per / 100 * climb_dis;
		double pos = climb_dis;
		int ret = 1;
		while (pos <= height)
		{
			pos -= slide_dis;		// at night the snail slip down
			if (pos < 0)
				break;
			climb_dis = climb_dis - fatique_dis < 0 ? 0 : climb_dis - fatique_dis;
			++ret;
			pos += climb_dis;		// next day it climbs up
		}
		printf("%s on day %d\n", pos < 0 ? "failure" : "success", ret);
	}
	return 0;
}
