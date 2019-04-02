#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int maxn = 30;
const int VISITED = 1;
const int UNVISITED = 0;
vi dfs_num, AdjList[maxn];

int nodeID(char c)
{
	return c - 'A';
}

void dfs(int u)
{
	dfs_num[u] = VISITED;
	for (int i = 0; i != (int) AdjList[u].size(); ++i)
	{
		int v = AdjList[u][i];
		if (dfs_num[v] == UNVISITED)
			dfs(v);
	}
	return;
}

int main()
{
	int nT;
	scanf("%d", &nT);
	getchar();
	string buffer;
	getline(cin, buffer);
	while (nT--)
	{
		getline(cin, buffer);
		int num = nodeID(buffer[0]) + 1;
		for (int i = 0; i != num; ++i)
			AdjList[i].clear();
		while (getline(cin, buffer) && buffer.size())
		{
			AdjList[nodeID(buffer[0])].push_back(nodeID(buffer[1]));
			AdjList[nodeID(buffer[1])].push_back(nodeID(buffer[0]));
		}
		int numCC = 0;
		dfs_num.assign(num, UNVISITED);
		for (int i = 0; i != num; ++i)
		{
			if (dfs_num[i] == UNVISITED)
			{
				numCC++;
				dfs(i);
			}
		}
		printf("%d\n%s", numCC, nT ? "\n" : "");
	}
	return 0;
}
