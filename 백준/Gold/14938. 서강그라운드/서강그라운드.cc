#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> v[101];
int ans[101];
int item[101];
priority_queue<pair<int, int>, vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
int Dijkstra(int start, int n, int m) {
	int aitem = 0;
	for (int i = 1; i <= n; i++)
	{
		ans[i] = 1234567890;
	}
	ans[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int newnode = v[node][i].first;
			int newcost = v[node][i].second;
			if (ans[newnode] > cost + newcost)
			{
				ans[newnode] = cost + newcost;
				pq.push({ ans[newnode], newnode });
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] <= m)
		{
			aitem += item[i];
		}
	}
	return aitem;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, r, aa = 0;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}
	for (int i = 0; i < r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	for (int i = 1; i <= n; i++)
	{

		int a = Dijkstra(i, n, m);
		if (aa < a)
		{
			aa = a;
		}
	}
	cout << aa;

}