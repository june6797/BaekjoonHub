#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[801];

int ans[801][801];
priority_queue<pair<int, int>, vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
void Dijkstra(int start) {
	pq.push({ 0, start });
	ans[start][start] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int nextnode = v[node][i].first;
			int ncost = v[node][i].second;
			if (cost + ncost < ans[start][nextnode])
			{
				ans[start][nextnode] = cost + ncost;
				pq.push({ cost + ncost, nextnode });
			}
		}
	}
}

int main() {
	int N, M, K, v1, v2;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			ans[i][j] = 1234567890;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	cin >> v1 >> v2;
	int a = 1234567890;
	Dijkstra(1);
	Dijkstra(v1);
	Dijkstra(v2);
	bool flag = false;
	if (ans[1][v1] == 1234567890 || ans[v1][v2] == 1234567890
		|| ans[v2][N] == 1234567890)
	{
		flag = true;
	}
	if (!flag)
	{
		a = min(a, ans[1][v1] + ans[v1][v2] + ans[v2][N]);
	}

	if (ans[1][v2] == 1234567890 || ans[v2][v1] == 1234567890
		|| ans[v1][N] == 1234567890)
	{
		flag = true;
	}

	if (!flag)
	{
		a = min(a, ans[1][v2] + ans[v2][v1] + ans[v1][N]);

	}
	if (flag)
	{
		cout << -1;
	}
	else
	{
		cout << a;
	}
}