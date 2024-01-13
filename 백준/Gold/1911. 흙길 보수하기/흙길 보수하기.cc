#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int x = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i].second > x)
		{
			x = max(x, v[i].first);
			int cnt = (v[i].second - 1 - x) / L + 1;
			ans += cnt;
			x += L * cnt;
		}

	}
	cout << ans;
}