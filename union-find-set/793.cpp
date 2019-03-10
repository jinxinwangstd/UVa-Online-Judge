#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;

class UnionFind
{
private:
	vi p, rank;			// storing its rank and parent node id
public:
	// Constructor
	UnionFind(int N)
	{
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i != N; ++i)
			p[i] = i;
	}
	// Find its set id
	int findSet(int i)
	{
		return p[i] == i ? i : (p[i] = findSet(p[i]));		// path compression
	}
	// Determine whether two nodes belong to the same set
	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}
	// unite two sets
	void unionSet(int i, int j)
	{
		if (!isSameSet(i, j))
		{
			int x = findSet(i);
			int y = findSet(j);
			if (rank[x] > rank[y])
				p[y] = x;
			else
			{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};


int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int N, caseNo = 0;
	scanf("%d", &N);
	getchar();
	getchar();
	while (caseNo < N)
	{
		++caseNo;
		printf("%s", caseNo == 1 ? "" : "\n");
		int num;
		scanf("%d", &num);
		UnionFind net(num + 1);
		getchar();
		string buffer;
		int success = 0, unsuccess = 0;
		while (getline(cin, buffer))
		{
			if (!buffer.compare(""))
				break;
			char cmd;
			int c1, c2;
			stringstream ss(buffer);
			ss >> cmd >> c1 >> c2;
			if (cmd == 'c')			// connect c1 and c2
				net.unionSet(c1, c2);
			else					// query whether c1 and c2 are connected
				net.isSameSet(c1, c2) ? success++ : unsuccess++;
		}
		printf("%d,%d\n", success, unsuccess);
	}
	return 0;
}

