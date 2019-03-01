#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 100;
const int num_rotates = 4;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int N, n;
	while (scanf("%d %d", &N, &n) == 2 && N && n)
	{
		char big[N][N], small[n][n], buffer[maxn];
		fgets(buffer, sizeof(buffer), stdin);
		// Read in the big grid
		for (int i = 0; i != N; ++i)
		{
			for (int j = 0; j != N; ++j)
				scanf("%c", &big[i][j]);
			fgets(buffer, sizeof(buffer), stdin);
		}
		// Read in the small grid
		for (int i = 0; i != n; ++i)
		{
			for (int j = 0; j != n; ++j)
				scanf("%c", &small[i][j]);
			fgets(buffer, sizeof(buffer), stdin);
		}
		// Check the appearing time of four rotated forms
		for (int r_i = 0; r_i != num_rotates; ++r_i)
		{
			int ret = 0;
			for (int i = 0; i <= N - n; ++i)
			{
				for (int j = 0; j <= N - n; ++j)
				{
					bool appear = true;
					for (int a = 0; a != n; ++a)
					{
						for (int b = 0; b != n; ++b)
						{
							if (small[a][b] != big[i + a][j + b])
							{
								appear = false;
								break;
							}
						}
						if (!appear)
							break;
					}
					ret += appear;
				}
			}
			printf("%s%d", r_i ? " " : "", ret);
			char tmp[n][n];
			// Copy to a temporary grid to serve the rotating process
			for (int i = 0; i != n; ++i)
				for (int j = 0; j != n; ++j)
					tmp[i][j] = small[i][j];
			// Rotate the grid 90 degrees clockwise
			for (int j = 0; j != n; ++j)
				for (int i = 0; i != n; ++i)
					small[j][i] = tmp[n - 1 - i][j];
		}
		printf("\n");
	}
	return 0;
}
