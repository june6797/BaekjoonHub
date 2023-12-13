#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<pair<int, int>> v;

		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({ a, b });
		}
		sort(v.begin(), v.end());
		int l = v.front().second;
		int ans = 1;
		for (size_t j = 1; j < v.size(); j++)
		{
			if (v[j].second < l)
			{
				ans++;
				l = v[j].second;
			}
		}
		cout << ans << "\n";
	}
}