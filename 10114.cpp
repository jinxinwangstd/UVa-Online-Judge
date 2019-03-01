#include <bits/stdc++.h>
using namespace std;

const double eps = 0.000000000000000001;
const int maxn = 105;
double depreciation[maxn];		// storing depreciation rates for every month

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int maxm, n;
	double down_payment, car_value;			// down payment is different from monthly payment
	while (scanf("%d%lf%lf%d", &maxm, &down_payment, &car_value, &n) == 4 && maxm > 0)
	{
		memset(depreciation, 0.0, sizeof(depreciation));
		while (n--)
		{
			int m;
			double d;
			scanf("%d%lf", &m, &d);
			depreciation[m] = d;
		}
		for (int i = 0; i <= maxm; ++i)			// every month that is not shown in the depreciation records have the same depreciation as the last month
		{
			if (depreciation[i] - 0.0 < eps)
				depreciation[i] = depreciation[i - 1];
		}
		double monthly_payment = car_value / maxm;			// monthly payment is derived from the amount of the loan dividing the number of months you pay
		int ret = 0;
		double owe = car_value;
		car_value = (car_value + down_payment) * (1 - depreciation[ret]);
		while (car_value - owe < -eps)
		{
			ret++;
			owe -= monthly_payment;
			car_value = car_value * (1 - depreciation[ret]);
		}
		printf("%d month%s\n", ret, ret == 1 ? "" : "s");
	}
	return 0;
}
