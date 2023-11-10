#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ans[20001];
vector<pair<int, int>> v[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijstra(int k) {
	ans[k] = 0;
	pq.push({ 0, k });
	while (!pq.empty())
	{
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int newnode = v[node][i].first;
			int newcost = ans[node] + v[node][i].second;
			if (ans[newnode] > newcost)
			{
				ans[newnode] = newcost;
				pq.push({ newcost, newnode });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;

	int k;
	cin >> k;
	for (int i = 0; i <= n; i++)
	{
		ans[i] = 123456789;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	Dijstra(k);
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 123456789)
		{
			cout << "INF\n";
		}
		else
		{
			cout << ans[i] << "\n";
		}
	}


}