#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[1001];
vector<pair<int, int>> rv[1001];

int ans[1001];
int rans[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
void Dijkstra(int start) {
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int nextnode = v[node][i].first;
			int ncost = v[node][i].second;
			if (cost + ncost < ans[nextnode])
			{
				ans[nextnode] = cost + ncost;
				pq.push({ cost + ncost, nextnode });
			}
		}
	}
}

void rDijkstra(int start) {
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < rv[node].size(); i++)
		{
			int nextnode = rv[node][i].first;
			int ncost = rv[node][i].second;
			if (cost + ncost < rans[nextnode])
			{
				rans[nextnode] = cost + ncost;
				pq.push({ cost + ncost, nextnode });
			}
		}
	}
}
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		ans[i] = 1234567890;
		rans[i] = 1234567890;
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		rv[b].push_back({ a, c });
	}

	Dijkstra(K);
	rDijkstra(K);

	int a = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i != K)
		{
			a = max(a, ans[i] + rans[i]);
		}

	}
	cout << a;
}