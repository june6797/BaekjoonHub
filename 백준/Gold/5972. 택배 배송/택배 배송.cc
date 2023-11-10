#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ans[50001];
vector<pair<int, int>> v[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijstra() {
	ans[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int newnode = v[node][i].first;
			int newcost = v[node][i].second;
			if (ans[node] + newcost < ans[newnode])
			{
				ans[newnode] = ans[node] + newcost;
				pq.push({ newcost, newnode });
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		ans[i] = 123456789;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	Dijstra();
	cout << ans[n];
}