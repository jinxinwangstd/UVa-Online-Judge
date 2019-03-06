#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<char> vc;
typedef map<char, vc> AdjList;

const int minn = 3;

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		getchar();
		set<char> wakeups;
		AdjList links;
		for (int i = 0; i != minn; ++i)
		{
			char c = getchar();
			wakeups.insert(c);
		}
		getchar();
		char x, y;
		while (m--)
		{
			cin >> x >> y;
			getchar();
			links[x].push_back(y);
			links[y].push_back(x);
		}
		int ret = 0;
		bool never = false;
		while (wakeups.size() != (unsigned) n)
		{
			vector<char> new_wakeup;
			for (AdjList::iterator iter = links.begin(); iter != links.end(); ++iter)
			{
				if (!wakeups.count(iter->first))
				{
					int num_wakeup_links = 0;
					for (vc::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
					{
						if (wakeups.count(*iter2))
							++num_wakeup_links;
					}
					if (num_wakeup_links >= 3)
						new_wakeup.push_back(iter->first);
				}
			}
			if (!new_wakeup.size())
			{
				printf("THIS BRAIN NEVER WAKES UP\n");
				never = true;
				break;
			}
			++ret;
			wakeups.insert(new_wakeup.begin(), new_wakeup.end());
		}
		if (!never)
			printf("WAKE UP IN, %d, YEARS\n", ret);
	}
	return 0;
}
