#include <bits/stdc++.h>
using namespace std;

// Sort three integers so that a <= b <= c
void sort(int& a, int& b, int& c)
{
	int tmp;
	if (a > b)			// ensure a <= b
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (b > c)			// ensure b <= c, so that c is largest one
	{
		tmp = b;
		b = c;
		c = tmp;
	}
	if (a > b)			// ensure a <= b
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	return;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n, caseNo = 1;
	scanf("%d", &n);
	while (caseNo <= n)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		sort(a, b, c);
		printf("Case %d: %d\n", caseNo++, b);
	}
	return 0;
}
