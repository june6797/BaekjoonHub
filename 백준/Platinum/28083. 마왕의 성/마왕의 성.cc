#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <regex>

#define mod 1000000007;
typedef long long int ll;

using namespace std;

int n, m;
int arr[1001][1001];
ll cost[1001][1001];
pair<int, int> parent[1001][1001];
ll ans[1001][1001];
bool visit[1001][1001];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, pair<int, int>>> v;

pair<int, int> find(int x, int y) {
	if (parent[x][y] == pair<int, int>{x, y})
	{
		return pair<int, int>{x, y};
	}
	else
	{
		return parent[x][y] = find(parent[x][y].first, parent[x][y].second);
	}
}

void unionfind(int x, int y, int nx, int ny) {
	pair<int, int> a = find(x, y);
	pair<int, int> b = find(nx, ny);
	if (a == b)
	{
		return;
	}
	parent[a.first][a.second] = b;
	cost[b.first][b.second] += cost[a.first][a.second];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			parent[i][j] = { i, j };
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> cost[i][j];
			v.push_back({ arr[i][j], {i, j} });
		}
	}
	sort(v.begin(), v.end());
	int temp = v[0].first;
	vector<int> xy;
	for (int i = 0; i < v.size(); i++)
	{
		if (temp == v[i].first)
		{
			xy.push_back(i);
		}
		else
		{
			for (int k = 0; k < xy.size(); k++)
			{
				pair<int, int> p = find(v[xy[k]].second.first, v[xy[k]].second.second);
				ans[v[xy[k]].second.first][v[xy[k]].second.second] = cost[p.first][p.second];
			}
			xy.clear();
			xy.push_back(i);
			temp = v[i].first;
		}
		int x = v[i].second.first;
		int y = v[i].second.second;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m
				&& arr[nx][ny] <= arr[x][y])
			{
				if (find(nx, ny) != find(x, y))
				{
					unionfind(x, y, nx, ny);
				}
			}
		}
	}
	for (int k = 0; k < xy.size(); k++)
	{
		pair<int, int> p = find(v[xy[k]].second.first, v[xy[k]].second.second);
		ans[v[xy[k]].second.first][v[xy[k]].second.second] = cost[p.first][p.second];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}