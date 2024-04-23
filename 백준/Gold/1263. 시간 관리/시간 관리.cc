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

vector<pair<int, int>> v;
int n;

bool com(pair<int, int> a, pair<int, int> b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ b, a });
	}
	sort(v.begin(), v.end(), com);
	int ans = v[0].first - v[0].second;
	int task = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i].first >= ans)
		{
			task += (v[i].first - ans);
		}
		else if (ans - v[i].first >= task)
		{
			task = 0;
		}
		else if (ans - v[i].first < task)
		{
			task -= (ans - v[i].first);
		}
		ans = v[i].first - v[i].second;
	}
	if (task > 0)
	{
		ans -= task;
	}
	if (ans < 0)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
}