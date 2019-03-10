#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int caseNO;
	scanf("%d", &caseNO);
	while (caseNO--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < b)
			cout << "<\n";
		else if (a > b)
			cout << ">\n";
		else
			cout << "=\n";
	}
	return 0;
}
