#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxs = 100000 + 50;
typedef struct tag_soldier
{
	int l;
	int r;
} soldier;
soldier soldiers[maxs];			// Linked list of soldiers

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int S, B;
	while (scanf("%d %d", &S, &B) == 2 && S)
	{
		for (int i = 1; i <= S; ++i)	// Form the links between elements
		{
			soldiers[i].l = i - 1;
			soldiers[i].r = i + 1;
		}
		while (B--)
		{
			int L, R;
			scanf("%d %d", &L, &R);
			// Form the new link between the adjacent elements of deleted ones
			soldiers[soldiers[L].l].r = soldiers[R].r;
			soldiers[soldiers[R].r].l = soldiers[L].l;
			if (soldiers[L].l != 0)
				printf("%d ", soldiers[L].l);
			else
				printf("* ");
			if (soldiers[R].r != S + 1)
				printf("%d\n", soldiers[R].r);
			else
				printf("*\n");
		}
		printf("-\n");
	}
	return 0;
}
