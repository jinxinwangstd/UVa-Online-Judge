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
	string s;
	while (getline(cin, s) && s[0] != '#')
	{
		bool ret = next_permutation(s.begin(), s.end());
		if (ret)
			cout << s << '\n';
		else
			cout << "No Successor\n";
	}
	return 0;
}
