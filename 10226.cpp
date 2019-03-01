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
	string name, buffer;
	getline(cin, buffer);
	getline(cin, buffer);
	int caseNo = 0;
	while (caseNo != N)
	{
		++caseNo;
		printf("%s", caseNo == 1 ? "" : "\n");
		map<string, int> ret;
		double total = 0.0;
		while (getline(cin, name))
		{
			if (name.compare("") == 0)
				break;
			++total;
			++ret[name];
		}
		for (map<string, int>::iterator iter = ret.begin(); iter != ret.end(); ++iter)
		{
			double per = iter->second * 100 / total;
			cout << iter->first << " ";
			printf("%.4f\n", per);
		}
	}
	return 0;
}
