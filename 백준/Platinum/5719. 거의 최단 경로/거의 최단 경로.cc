#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1234567890
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m, s, e;
vector<pii> edges[501];
bool visited[501];
int dist[501];
vector<int> path[501];
void Dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int t = pq.top().second;
		pq.pop();
		for (int i = 0; i < edges[t].size(); i++)
		{
			int next = edges[t][i].first;
			int next_cost = edges[t][i].second;
			if (next_cost == -1)
			{
				continue;
			}
			if (dist[t] + next_cost < dist[next])
			{
				dist[next] = dist[t] + next_cost;
				path[next].clear();
				path[next].push_back(t);
				pq.push({ dist[next], next });
			}
			else if (dist[t] + next_cost == dist[next])
			{
				path[next].push_back(t);
			}
		}
	}
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (visited[t])
		{
			continue;
		}
		visited[t] = 1;
		for (int i = 0; i < path[t].size(); i++)
		{
			int next = path[t][i];
			for (int j = 0; j < edges[next].size(); j++)
			{
				if (edges[next][j].first == t)
				{
					edges[next][j].second = -1;
				}
			}
			q.push(next);

		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		for (int i = 0; i < 501; i++)
		{
			dist[i] = INF;
			path[i].clear();
			visited[i] = 0;
			edges[i].clear();
		}
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			break;
		}
		cin >> s >> e;

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edges[a].push_back({ b, c });
		}
		Dijkstra(s);
		BFS(e);
		for (int i = 0; i < 501; i++)
		{
			dist[i] = INF;
		}
		Dijkstra(s);
		if (dist[e] == INF)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << dist[e] << "\n";
		}
	}
}