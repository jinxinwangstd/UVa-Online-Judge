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
	int nd;
	while (scanf("%d", &nd) == 1 && nd)
	{
		ll ret = 0;				// the total amount of promotion may be overflow for an int object
		multiset<int> bills;
		while (nd--)
		{
			int nb;
			scanf("%d", &nb);
			while (nb--)
			{
				int bill;
				scanf("%d", &bill);
				bills.insert(bill);
			}
			multiset<int>::iterator li = bills.begin();				// get the iterator of the min value
			multiset<int>::iterator hi = --bills.end();	// get the iterator of the max value
			ret += *hi - *li;
			bills.erase(li);
			bills.erase(hi);
		}
		printf("%ld\n", ret);
	}
	return 0;
}
