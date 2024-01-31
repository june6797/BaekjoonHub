#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
vector<pair<int, int>> v[1001];
int ans = 0;
void BFS(int start) {
	arr[start] = 1;
	for (int i = 0; i < v[start].size(); i++)
	{
		q.push({ v[start][i].second, v[start][i].first });
	}
	while (!q.empty())
	{
		int node = q.top().second;
		int cost = q.top().first;

		q.pop();
		if (arr[node] == 0)
		{
			arr[node] = 1;
			ans += cost;
			for (int i = 0; i < v[node].size(); i++)
			{
				if (arr[v[node][i].first] == 0)
				{
					q.push({ v[node][i].second, v[node][i].first });
				}
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	BFS(1);
	cout << ans;
}