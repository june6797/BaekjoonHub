#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ans[1001];
int visit[1001];
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijstra(int k) {
	ans[k] = 0;
	pq.push({ 0, k });
	while (!pq.empty())
	{
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (visit[node] == 0)
		{
			visit[node] = 1;
			for (int i = 0; i < v[node].size(); i++)
			{
				int newnode = v[node][i].first;
				int newcost = v[node][i].second;
				if (ans[newnode] > ans[node] + newcost)
				{
					ans[newnode] = ans[node] + newcost;
					pq.push({ ans[newnode], newnode });
				}
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
	int start, end;
	cin >> start >> end;
	Dijstra(start);
	cout << ans[end];

}