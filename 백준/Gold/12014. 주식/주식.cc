#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <regex>
typedef long long int ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		vector<int> v;
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			if (v.size() == 0)
			{
				v.push_back(num);
			}
			else
			{
				if (v[v.size() - 1] < num)
				{
					v.push_back(num);
				}
				else
				{
					int start = 0;
					int end = v.size() - 1;
					while (start < end)
					{
						int mid = (start + end) / 2;
						if (v[mid] < num)
						{
							start = mid + 1;
						}
						else
						{
							end = mid;
						}
					}
					v[start] = num;
				}
			}
		}
		cout << "Case #" << test << "\n";
		if (v.size() >= k)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}
}