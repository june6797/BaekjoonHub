#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <string>
typedef long long int ll;
using namespace std;

vector<int> v[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		string str;
		int k;
		cin >> str >> k;
		for (int i = 0; i < 26; i++) {
			v[i].clear();
		}
		for (int i = 0; i < str.size(); i++)
		{
			v[str[i] - 'a'].push_back(i);
		}
		int small = 123456789;
		int big = -1;
		for (int i = 0; i < 26; i++)
		{
			if (v[i].size() >= k)
			{
				for (int j = 0; j <= v[i].size() - k; j++)
				{
					small = min(small, v[i][j + k - 1] - v[i][j] + 1);
					big = max(big, v[i][j + k - 1] - v[i][j] + 1);
				}
			}
		}
		if (small == 123456789)
		{
			cout << "-1\n";
		}
		else
		{
			cout << small << " " << big << "\n";
		}
	}

}