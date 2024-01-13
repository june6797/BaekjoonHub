#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end());
	int f = v[0].first;
	int s = v[0].second;
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		if (v[i].first <= s)
		{
			if (v[i].second > s)
			{
				s = v[i].second;
			}
		}
		else
		{
			ans += s - f;
			f = v[i].first;
			s = v[i].second;
		}
	}
	ans += s - f;
	cout << ans;
}