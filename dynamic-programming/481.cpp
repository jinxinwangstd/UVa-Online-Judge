#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

// Reconstruct the LIS from original list and predecessor list
void reconstruct_print(vector<int>& a, int *p, int end)
{
	stack<int> l;
	while (end >= 0)	// backtracking with predecessor list to find all elements of LIS
	{
		l.push(a[end]);
		end = p[end];
	}
	while (!l.empty())
	{
		printf("%d\n", l.top());
		l.pop();
	}
	return;
}

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	vector<int> A;			// original list
	int n;
	while (scanf("%d", &n) != EOF)
		A.push_back(n);
	n = A.size();
	int L[n];				// storing the sorted list
	int L_id[n];			// storing the id of each element of L in the original list
	int predecessors[n];	// storing the id of the predecessor of the element when it is inserted to L
	int l_size = 0, l_end = 0;		// record the length of L and its last element's id
	for (int i = 0; i != n; ++i)
	{
		int pos = lower_bound(L, L + l_size, A[i]) - L;
		L[pos] = A[i];
		L_id[pos] = i;
		predecessors[i] = pos ? L_id[pos - 1] : -1;
		if (pos == l_size)		// append an element to the end of L
		{
			++l_size;
			l_end = i;
		}
	}
	printf("%d\n-\n", l_size);
	reconstruct_print(A, predecessors, l_end);
	return 0;
}
