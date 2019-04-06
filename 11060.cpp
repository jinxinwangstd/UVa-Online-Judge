#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int maxn = 100 + 5;
int g[maxn][maxn], n, num_inedges[maxn];

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int caseNo = 0;
	string buffer;
	while (cin)
	{
		getline(cin, buffer);
		n = stoi(buffer);
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
		memset(g, 0, sizeof(g));
		memset(num_inedges, 0, sizeof(num_inedges));
		for (int i = 0; i != num_edges; ++i)
		{
			string less, more;
			cin >> less >> more;
			g[ids[less]][ids[more]] = 1;
			num_inedges[ids[more]]++;
		}
		if (num_edges)
			getline(cin, buffer);
		// Kahn's algorithm
		vector<int> l;	// topological sort list
		queue<int> q;	// queue for vertices without incoming edges
		for (int u = 0; u != n; ++u)	// find vertices without incoming edges
			if (!num_inedges[u])
				q.push(u);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			l.push_back(u);
			// eliminate all outcoming edges for vertex u
			for (int v = 0; v != n; ++v)
			{
				if (g[u][v])
				{
					num_inedges[v]--;
					if (!num_inedges[v])	// check whether v becomes vertex without incoming edges
						q.push(v);
					g[u][v] = 0;
				}
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", ++caseNo);
		for (vector<int>::iterator iter = l.begin(); iter != l.end(); ++iter)
			cout << " " << record[*iter];
		printf(".\n\n");
		getline(cin, buffer);
	}
	return 0;
}

