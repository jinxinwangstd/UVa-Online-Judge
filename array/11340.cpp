#include <bits/stdc++.h>
#define FI
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int maxn = 256;
const int maxl = 150000 + 50;
int values[maxn];				// Direct Addressing Table

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	while (N--)
	{
		memset(values, 0, sizeof(values));
		int ret = 0;
		int num_chars;
		scanf("%d", &num_chars);
		string value_pair;
		getline(cin, value_pair);
		while (num_chars--)
		{
			getline(cin, value_pair);
			stringstream ss(value_pair);
			char c;
			int v;
			ss >> c >> v;
			values[c + 128] = v;	// The range for char is [-128, 127], we need to make it mapping to [0, 255]
		}
		int num_lines;
		scanf("%d", &num_lines);
		getline(cin, value_pair);
		char line[maxl];
		while (num_lines--)
		{
			memset(line, 0, sizeof(line));
			fgets(line, sizeof(line), stdin);
			int length = strlen(line);
			for (int i = 0; i != length; ++i)
				ret += values[line[i] + 128];	// use offset to map char value to [0, 255]
		}
		printf("%d.%d%d$\n", ret / 100, (ret / 10) % 10, ret % 10);
	}
	return 0;
}
