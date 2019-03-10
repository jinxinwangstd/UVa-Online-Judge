#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	vector<int> seq;
	int n;
	while (cin >> n)
	{
		seq.push_back(n);
		int num = seq.size();
		int offset1, offset2;	// middle values' offsets compared to the first element
		ll ret = 0;				// using long int because it contains the sum of two integers
		if (num % 2)
			offset1 = offset2 = (num - 1) / 2;
		else
		{
			offset2 = num / 2;
			offset1 = offset2 - 1;
		}
		nth_element(seq.begin(), seq.begin() + offset1, seq.end());
		ret += *(seq.begin() + offset1);
		nth_element(seq.begin(), seq.begin() + offset2, seq.end());
		ret += *(seq.begin() + offset2);
		ret /= 2;
		cout << ret << '\n';
	}
	return 0;
}
