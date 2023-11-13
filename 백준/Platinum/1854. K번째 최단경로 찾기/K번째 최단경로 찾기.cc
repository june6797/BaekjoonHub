#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ans[1001];
vector<pair<int, int>> v[1001];
priority_queue<int> pq[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void Dijkstra(int start, int k) {
	q.push({ 0, 1 });
	pq[1].push(0);
	while (!q.empty())
	{
		int cost = q.top().first;
		int node = q.top().second;
		q.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int newnode = v[node][i].first;
			int newcost = cost + v[node][i].second;
			if (pq[newnode].size() < k)
			{
				pq[newnode].push(newcost);
				q.push({ newcost, newnode });
			}
			else if (pq[newnode].top() > newcost)
			{
				pq[newnode].pop();
				pq[newnode].push(newcost);
				q.push({ newcost, newnode });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	Dijkstra(1, k);
	for (int i = 1; i <= n; i++)
	{
		if (pq[i].size() == k)
		{
			cout << pq[i].top() << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}

}