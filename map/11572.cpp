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
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int num;
		scanf("%d", &num);
		map<int, int> snow_pos;	// to record the latest occurrence position of each snowflake
		int start = 1;			// start position of a non-repeated sequence
		int ret = 0;			// result: the length of the longest non-repeated sequence
		int pos = 0;			// the position of snowflake which we currently inspect
		while (num--)
		{
			++pos;
			int snow_index;
			scanf("%d", &snow_index);
			if (!snow_pos.count(snow_index))		// never occurred
				snow_pos[snow_index] = pos;
			else
			{
				if (snow_pos[snow_index] >= start)	// occurred and in the current non-repeated sequence
				{
					int length = pos - start;
					if (length > ret)
						ret = length;
					start = snow_pos[snow_index] + 1;
				}
				snow_pos[snow_index] = pos;			// update the latest occurrence position
			}
		}
		// Handle the last unrepeated sequence
		int last_seq_length = pos - start + 1;
		if (last_seq_length > ret)
			ret = last_seq_length;
		printf("%d\n", ret);
	}
	return 0;
}
