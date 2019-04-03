#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

// Trick to explore an implicit 2D grid
// The order is S, SE, E, NE, N, NW, W, SW (starting from S in counter-clockwise)
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};		// variation in x axis (row number)
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};		// variation in y axis (column number)
const int num_directions = 8;
const int maxn = 100 + 5;
const int VISITED = 1, UNVISITED = 0;
int g[maxn][maxn];			// 2D implicit graph
int dfs_num[maxn][maxn];	// dfs array to avoid cycles
int R, C;					// the size of the grid

// DFS to label (color) and count the size of each component
int floodfill(int r, int c, char c1)
{
	if (r < 0 || r >= R || c < 0 || c >= C)	// out of the grid
		return 0;
	if (g[r][c] != c1)		// does not have the corresponding color
		return 0;
	if (dfs_num[r][c] == VISITED)	// already visited
		return 0;
	dfs_num[r][c] = VISITED;
	int ans = 1;
	for (int d = 0; d != num_directions; ++d)
		ans += floodfill(r + dr[d], c + dc[d], c1);
	return ans;
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
		R = 0;
		C = 0;
		while (getline(cin, buffer) && isalpha(buffer[0]))
		{
			C = (int) buffer.size();
			R++;
			for (int i = 0; i != C; ++i)
				g[R - 1][i] = buffer[i];
		}
		while (!buffer.empty())
		{
			memset(dfs_num, UNVISITED, sizeof(dfs_num));
			stringstream ss(buffer);
			int r, c;
			ss >> r >> c;
			printf("%d\n", floodfill(r - 1, c - 1, 'W'));	// be careful about 0-based indexing or 1-based indexing
			getline(cin, buffer);
		}
		printf("%s", nT ? "\n" : "");
	}
	return 0;
}
