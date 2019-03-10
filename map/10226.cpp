#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 100;
char buffer[maxn];		// store useless input like blank lines

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	fgets(buffer, sizeof(buffer), stdin);
	fgets(buffer, sizeof(buffer), stdin);
	int caseNo = 0;
	while (caseNo != N)
	{
		++caseNo;
		printf("%s", caseNo == 1 ? "" : "\n");
		map<string, int> ret;
		string name;
		double total = 0.0;
		// Record appearance of each tree
		while (fgets(buffer, sizeof(buffer), stdin) && isalpha(buffer[0]))
		{
			++total;
			++ret[name];
		}
		// Output the appearance percentage of each tree kind
		for (map<string, int>::iterator iter = ret.begin(); iter != ret.end(); ++iter)
		{
			double per = iter->second * 100 / total;
			cout << iter->first << " ";
			printf("%.4f\n", per);
		}
	}
	return 0;
}
