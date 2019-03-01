#include <bits/stdc++.h>
using namespace std;

const double eps = 0.0000000000000000000000001;
const int maxn = 100;
char candidate_name[maxn];
char final_name[maxn];
char req[maxn];				// storing requirement name

void consumeLine()
{
	char c;
	while ((c = getchar()) != '\n' && c != '\0')
		;
	return;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n, p, caseNo = 1;
	while (scanf("%d%d", &n, &p) == 2 && n && p)
	{
		consumeLine();
		int i = 0;
		for (i = 0; i != n; ++i)
			consumeLine();
		memset(final_name, 0, sizeof(final_name));
		double final_d = 10000000000000000000000000000.0, final_r = 0;
		while (p--)
		{
			memset(candidate_name, 0, sizeof(candidate_name));
			fgets(candidate_name, sizeof(candidate_name), stdin);
			candidate_name[strlen(candidate_name) - 1] = '\0';			// replace the end newline character with null character
			double d;
			int r;
			scanf("%lf%d", &d, &r);
			consumeLine();
			int i = 0;
			for (i = 0; i != r; ++i)
				consumeLine();
			if (r > final_r)
			{
				final_r = r;
				final_d = d;
				strcpy(final_name, candidate_name);
			}
			else if (r == final_r && d - final_d < -eps)
			{
				final_d = d;
				strcpy(final_name, candidate_name);
			}
		}
		if (caseNo > 1)
			printf("\n");
		printf("RFP #%d\n%s\n", caseNo++, final_name);
	}
	return 0;
}
