#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

int n, m;
int ans = 1234567890;
int arr[51][51];
vector<pair<int, int>> virus;
bool check[10];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[51][51];
int checkarr[51][51];

int selectcnt() {
	int cnt = 0;
	for (int i = 0; i < virus.size(); i++)
	{
		if (check[i])
		{
			cnt++;
		}
	}
	return cnt;
}

int BFS() {

	queue<pair<pair<int, int>, int>> q;
	memset(visit, 0, sizeof(visit));
	memset(checkarr, 0, sizeof(checkarr));
	for (int i = 0; i < virus.size(); i++)
	{
		if (check[i])
		{
			q.push({ virus[i], 0 });
			visit[virus[i].first][virus[i].second] = 1;
		}
	}

	while (!q.empty())
	{
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int dep = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n
				&& !visit[nx][ny] && arr[nx][ny] != 1)
			{
				q.push({ { nx, ny }, dep + 1 });
				visit[nx][ny] = 1;
				if (arr[nx][ny] == 0)
				{
					checkarr[nx][ny] = dep + 1;
				}
				else if (arr[nx][ny] == 2) {
					checkarr[nx][ny] = 0;
				}
			}
		}
	}
	int ma = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0 && !visit[i][j])
			{
				return -1;
			}
			ma = max(ma, checkarr[i][j]);
		}
	}
	return ma;
}
void DFS(int idx, int dep) {
	if (dep == m)
	{
		int k = selectcnt();
		if (k == m)
		{
			int tt = BFS();
			if (tt != -1)
			{
				ans = min(ans, tt);
			}
		}
		return;
	}

	for (int i = idx; i < virus.size(); i++)
	{
		if (!check[i])
		{
			check[i] = true;
			DFS(i + 1, dep + 1);
			check[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				virus.push_back({ i, j });
			}
		}
	}
	DFS(0, 0);
	if (ans == 1234567890)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
}
