#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[10001];
int ans[10001];
int visit[10001];
vector<pair<int, int>> v[10001];
vector<pair<int, int>> rv[10001];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		arr[b]++;
		rv[b].push_back({ a, c });
	}
	int start, end;
	cin >> start >> end;
	q.push(start);
	while (!q.empty())
	{
		int a = q.front();
		for (int i = 0; i < v[a].size(); i++)
		{
			arr[v[a][i].first]--;
			ans[v[a][i].first] = max(ans[v[a][i].first], ans[a] + v[a][i].second);
			if (arr[v[a][i].first] == 0)
			{
				q.push(v[a][i].first);
			}
		}
		q.pop();
	}
	cout << ans[end] << "\n";
	int l = ans[end];
	int cnt = 0;
	q.push(end);
	visit[end] = 1;
	while (!q.empty())
	{
		int a = q.front();
		for (int i = 0; i < rv[a].size(); i++)
		{
			if (ans[rv[a][i].first] == ans[a] - rv[a][i].second) {
				cnt++;
				if (visit[rv[a][i].first] == 0)
				{
					visit[rv[a][i].first] = 1;
					q.push(rv[a][i].first);
				}
			}
		}
		q.pop();
	}
	cout << cnt;
}