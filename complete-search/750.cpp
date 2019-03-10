#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

int row[8], N, a, b, lineCounter;

// Place the next queen at the row r and the column c. If it does not satisfy the constraints, return false; otherwise return true
bool place(int r, int c)
{
	for (int prev = 0; prev < c; ++prev)
	{
		if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
			return false;
	}
	return true;
}

// Recursively arrange the queen on column from 0 to 7
void backtrack(int c)
{
	if (c == 8 && row[b] == a)	// all 8 queens have been placed, print out results
	{
		printf("%2d      %d", ++lineCounter, row[0] + 1);
		for (int j = 1; j < 8; ++j)
			printf(" %d", row[j] + 1);
		printf("\n");
	}
	// recursively determine the column number of queens in rows from 0 to 7
	for (int r = 0; r < 8; ++r)
	{
		if (place(r, c))
		{
			row[c] = r;
			backtrack(c + 1);
		}
	}
	return;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d %d", &a, &b);
		// switch to the 0-based index
		a--;
		b--;
		memset(row, 0, sizeof(row));
		lineCounter = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		if (N)
			printf("\n");
	}
	return 0;
}
