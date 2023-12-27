#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		v.push_back({ s, e });
	}
	sort(v.begin(), v.end());
	pq.push(v[0].second);
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		int start = v[i].first;
		int end = v[i].second;
		while (!pq.empty() && pq.top() <= start)
		{
			pq.pop();
		}
		pq.push(end);
		ans = max(ans, static_cast<int>(pq.size()));
	}
	cout << ans;
}