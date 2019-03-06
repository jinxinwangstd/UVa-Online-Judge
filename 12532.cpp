#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;

class SegmentTree
{
private:
	vi st, A;
	int n;
	int left(int p)
	{
		return (p << 1);
	}
	int right(int p)
	{
		return (p << 1) + 1;
	}
	void build(int p, int L, int R)
	{
		if (L == R)
		{
			st[p] = A[L] ? (A[L] > 0 ? 1 : -1) : 0;
		}
		else
		{
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			if (!p1 || !p2)
				st[p] = 0;
			else
				st[p] = (p1 == p2 ? 1 : -1);
		}
	}
	int findP(int pos, int p, int L, int R)
	{
		if (L == R)
			return p;
		if (pos <= (L + R) / 2)
			return findP(pos, left(p), L, (L + R) / 2);
		else
			return findP(pos, right(p), (L + R) / 2 + 1, R);
	}
	int rsq(int p, int L, int R, int i, int j)
	{
		if (i > R || j < L)
			return -2;
		if (L >= i && R <= j)
			return st[p];

		int p1 = rsq(left(p), L, (L + R) / 2, i, j);
		int p2 = rsq(right(p), (L + R) / 2 + 1, R, i, j);
		if (p1 == -2)
			return p2;
		if (p2 == -2)
			return p1;
		if (!p1 || !p2)
			return 0;
		else
			return (p1 == p2 ? 1 : -1);
	}
public:
	SegmentTree(const vi& _A)
	{
		A = _A;
		n = _A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}
	int rsq(int i, int j)
	{
		return rsq(1, 0, n - 1, i, j);
	}
	void update(int pos, int val)
	{
		int p = findP(pos, 1, 0, n - 1);
		A[pos] = val;
		if (st[p] == 0)
			build(1, 0, n - 1);
		else if (!val)
		{
			while (p > 0)
			{
				st[p] = 0;
				p = p >> 1;
			}
		}
		else
		{
			int old_sig = st[p], new_sig = val > 0 ? 1 : -1;
			while (p > 0)
			{
				st[p] = st[p] / old_sig * new_sig;
				p >>= 1;
			}
		}
		return;
	}
};

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF)
	{
		vi a;
		while (n--)
		{
			int num;
			scanf("%d", &num);
			a.push_back(num);
		}
		getchar();
		SegmentTree seq(a);
		char cmd;
		int i, v;
		while (k--)
		{
			scanf("%c %d %d", &cmd, &i, &v);
			getchar();
			if (cmd == 'C')
				seq.update(i - 1, v);
			else
			{
				int ret = seq.rsq(i - 1, v - 1);
				printf("%s", ret == 0 ? "0" : (ret > 0 ? "+" : "-"));
			}
		}
		printf("\n");
	}
	return 0;
}
