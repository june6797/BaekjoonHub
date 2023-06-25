#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[20001];
int dist[20001];
priority_queue<pair<int, int>> pq;

void dijkstra(int K) {
	dist[K] = 0;
	pq.push({ 0, K });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int next = adj[cur][i].first;
			int ncost = cost + adj[cur][i].second;
			if (ncost < dist[next])
			{
				dist[next] = ncost;
				pq.push({ -ncost, next });
			}
		}

	}
}


int main() {
	int V, E, K, u, v, w;
	cin >> V >> E >> K;
	for (int i = 0; i < 20001; i++)
	{
		dist[i] = 999999;
	}
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}
	dijkstra(K);
	for (int i = 1; i < V + 1; i++)
	{
		if (i == K)
		{

		}
		if (dist[i] == 999999)
		{
			cout << "INF\n";
		}
		else
		{
			cout << dist[i] << "\n";
		}
	}
}