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
	int n;
	while (scanf("%d", &n) && n)
	{
		ll ret = 0;			// the total cost may be overflow for an int variable
		priority_queue<int, vector<int>, greater<int> > nums;	// to maintain the smallest element in the front, we use the greater class
		while (n--)
		{
			int num;
			scanf("%d", &num);
			nums.push(num);
		}
		while (nums.size() != 1)
		{
			int num1 = nums.top();
			nums.pop();
			int num2 = nums.top();
			nums.pop();
			int sum = num1 + num2;
			ret += sum;
			nums.push(sum);
		}
		printf("%ld\n", ret);
	}
	return 0;
}
