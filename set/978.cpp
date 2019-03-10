#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

// Simulate a single round of fight
void fight(multiset<int, greater<int> >& a, multiset<int, greater<int> >& b, int num)
{
	multiset<int> a_survivors, b_survivors;
	while (num--)
	{
		multiset<int>::iterator as = a.begin(), bs = b.begin();
		if (as == a.end() || bs == b.end())
			break;
		if (*as > *bs)
			a_survivors.insert(*as - *bs);
		else if (*bs > *as)
			b_survivors.insert(*bs - *as);
		a.erase(as);
		b.erase(bs);
	}
	a.insert(a_survivors.begin(), a_survivors.end());
	b.insert(b_survivors.begin(), b_survivors.end());
	return;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	int caseNo = 0;
	while (caseNo != N)
	{
		++caseNo;
		printf("%s", caseNo == 1 ? "" : "\n");
		int b, sg, sb;
		scanf("%d%d%d", &b, &sg, &sb);
		multiset<int, greater<int> > blue, green;
		// Read in two sides' soldiers
		for (int i = 0; i != sg; ++i)
		{
			int soldier;
			scanf("%d", &soldier);
			green.insert(soldier);
		}
		for (int i = 0; i != sb; ++i)
		{
			int soldier;
			scanf("%d", &soldier);
			blue.insert(soldier);
		}
		// Battle until one group is defeated
		while (!blue.empty() && !green.empty())
			fight(blue, green, b);
		if (!blue.empty())
		{
			printf("blue wins\n");
			for (multiset<int>::iterator iter = blue.begin(); iter != blue.end(); ++iter)
				printf("%d\n", *iter);
		}
		else if (!green.empty())
		{
			printf("green wins\n");
			for (multiset<int>::iterator iter = green.begin(); iter != green.end(); ++iter)
				printf("%d\n", *iter);
		}
		else
			printf("green and blue died\n");
	}
	return 0;
}
