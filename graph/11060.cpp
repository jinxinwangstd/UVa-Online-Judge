#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int maxn = 100 + 5;
vi g[maxn];
int n, num_inedges[maxn];

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int caseNo = 0;
	string buffer;
	while (scanf("%d", &n) != EOF)
	{
		getline(cin, buffer);
		// To assign unique id to each beverage
		map<string, int> ids;
		vector<string> record;
		for (int i = 0; i != n; ++i)
		{
			getline(cin, buffer);
			ids[buffer] = i;
			record.push_back(buffer);
		}
		getline(cin, buffer);
		int num_edges = stoi(buffer);
		memset(num_inedges, 0, sizeof(num_inedges));
		// Read in all directed edges
		for (int i = 0; i != num_edges; ++i)
		{
			string less, more;
			cin >> less >> more;
			g[ids[less]].push_back(ids[more]);
			num_inedges[ids[more]]++;
		}
		if (num_edges)					// number of edges could be zero
			getline(cin, buffer);
		// Kahn's algorithm
		vector<int> l;	// topological sort list
		priority_queue<int, vector<int>, greater<int> > q;	// priority queue for vertices without incoming edges
		for (int u = 0; u != n; ++u)	// find vertices without incoming edges
			if (!num_inedges[u])
				q.push(u);
		while (!q.empty())
		{
			int u = q.top();
			q.pop();
			l.push_back(u);
			// eliminate all outcoming edges for vertex u
			vi adjs = g[u];
			int num = (int) adjs.size();
			for (int i = 0; i != num; ++i)
			{
				--num_inedges[adjs[i]];
				if (!num_inedges[adjs[i]])
					q.push(adjs[i]);
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", ++caseNo);
		for (vector<int>::iterator iter = l.begin(); iter != l.end(); ++iter)
			cout << " " << record[*iter];
		printf(".\n\n");
	}
	return 0;
}

