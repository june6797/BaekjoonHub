#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
int dist[1001];
int road[1001];

void Dij(int start, int end) {
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;

		pq.pop();
		if (node == end)
		{
			break;
		}
		for (int i = 0; i < v[node].size(); i++)
		{
			int newnode = v[node][i].first;
			int newcost = v[node][i].second;
			if (dist[newnode] > cost + newcost)
			{
				road[newnode] = node;
				dist[newnode] = cost + newcost;
				pq.push({ dist[newnode], newnode });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, s, e;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		dist[i] = 1234567890;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	cin >> s >> e;
	Dij(s, e);
	cout << dist[e] << "\n";
	int temp = e;
	vector<int> r;
	while (temp)
	{
		r.push_back(temp);
		temp = road[temp];
	}
	cout << r.size() << "\n";
	for (int i = r.size() - 1; i >= 0; i--)
	{
		cout << r[i] << " ";
	}
}