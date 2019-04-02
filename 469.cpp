#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int num_directions = 8;
const int maxn = 100 + 5;
const int VISITED = 1, UNVISITED = 0;
int g[maxn][maxn], dfs_num[maxn][maxn], R, C;

int floodfill(int r, int c, char c1)
{
	if (r < 0 || r >= R || c < 0 || c >= C)
		return 0;
	if (g[r][c] != c1)
		return 0;
	if (dfs_num[r][c] == VISITED)
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
