#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 100;
char buffer[maxn];
const int maxv = 26;

// return the id of an uppercase alphabet
int charId(char c)
{
	return c - 'A';
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		bitset<maxv> vertices_with_edge;		// record whether a vertex has edges
		int num_edges = 0, num_vertices = 0;
		while (scanf("%s", buffer) && buffer[0] != '*')
		{
			int v1 = charId(buffer[1]);
			int v2 = charId(buffer[3]);
			// record vertices which have edges
			vertices_with_edge.set(v1);
			vertices_with_edge.set(v2);
			++num_edges;
		}
		scanf("%s", buffer);
		num_vertices = (strlen(buffer) + 1) / 2;
		int num_acorn = num_vertices - vertices_with_edge.count();
		int num_tree = num_vertices - num_edges - num_acorn;
		printf("There are %d tree(s) and %d acorn(s).\n", num_tree, num_acorn);
	}
	return 0;
}
