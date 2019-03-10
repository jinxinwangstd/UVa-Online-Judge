#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

int n, ans;
char board[20][20];
bitset<30> rw, left_diagonal, right_diagonal;

void backtrack(int c)
{
	if (c == n)
	{
		ans++;
		return;
	}
	for (int r = 0; r < n; ++r)
	{
		if (board[r][c] != '*' && !rw[r] && !left_diagonal[r - c + n - 1] && !right_diagonal[r + c])
		{
			rw[r] = left_diagonal[r - c + n - 1] = right_diagonal[r + c] = true;
			backtrack(c + 1);
			rw[r] = left_diagonal[r - c + n - 1] = right_diagonal[r + c] = false;
		}
	}
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int caseNo = 0;
	while (scanf("%d", &n) && n)
	{
		getchar();
		++caseNo;
		ans = 0;
		for (int i = 0; i != n; ++i)
			fgets(&board[i][0], sizeof(board[i]), stdin);
		rw.reset();
		left_diagonal.reset();
		right_diagonal.reset();
		backtrack(0);
		printf("Case %d: %d\n", caseNo, ans);
	}
	return 0;
}
