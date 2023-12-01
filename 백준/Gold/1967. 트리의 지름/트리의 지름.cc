#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v[10001];
bool visit[10001];
int ans, first;
void DFS(int start, int cost) {
	visit[start] = 1;
	if (cost > ans)
	{
		ans = cost;
		first = start;
	}
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visit[v[start][i].first] == 0)
		{
			DFS(v[start][i].first, cost + v[start][i].second);
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	DFS(1, 0);
	for (int i = 0; i <= n; i++)
	{
		visit[i] = 0;
	}
	ans = 0;
	DFS(first, 0);
	cout << ans;
}