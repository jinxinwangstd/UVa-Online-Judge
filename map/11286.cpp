#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int num_classes = 5;

int main()
{
#ifdef FI
	freopen("input.txt", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) && n)
	{
		string buffer;
		getline(cin, buffer);
		map<set<int>, int> record;
		while (n--)					// build the combination popularity (frequency)
		{
			getline(cin, buffer);
			stringstream ss(buffer);
			set<int> combination;
			int course_num;
			for (int i = 0; i != num_classes; ++i)
			{
				ss >> course_num;
				combination.insert(course_num);
			}
			++record[combination];
		}
		int pop = 0, num_people = 0;	// num_people is the number of people choose the combinations with highest popularity, they may have different combinations
		for (map<set<int>, int>::iterator iter = record.begin(); iter != record.end(); ++iter)
		{
			if (iter->second > pop)			// a new combination with highest popularity
				pop = num_people = iter->second;
			else if (iter->second == pop)	// a same popularity combination
				num_people += iter->second;
		}
		printf("%d\n", num_people);
	}
	return 0;
}
