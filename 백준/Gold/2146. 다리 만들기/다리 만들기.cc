#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int arr[102][102];
bool visit[102][102];
int lcnt;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> landout;
	vector<pair<int, int>> landin;
	visit[x][y] = 1;
	q.push({ x, y });
	while (!q.empty())
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		bool check = false;
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n
				&& !visit[nx][ny] && arr[nx][ny] == 1) {
				q.push({ nx, ny });
				visit[nx][ny] = 1;
			}
			if (nx >= 0 && nx < n && ny >= 0 && ny < n
				&& arr[nx][ny] == 0)
			{
				check = true;
			}
		}
		if (check) {
			landout.push_back({ tx, ty });
		}
		else
		{
			landin.push_back({ tx, ty });
		}
	}
	for (int i = 0; i < landout.size(); i++)
	{
		arr[landout[i].first][landout[i].second] = lcnt;
	}
	for (int i = 0; i < landin.size(); i++)
	{
		arr[landin[i].first][landin[i].second] = -1;
	}
}

int BFS2(int x, int y) {
	int landnum = arr[x][y];
	memset(visit, 0, sizeof(visit));
	visit[x][y] = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y }, 0 });
	while (!q.empty())
	{
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int len = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n
				&& !visit[nx][ny]) {
				if (arr[nx][ny] == 0)
				{
					q.push({ { nx, ny }, len + 1 });
					visit[nx][ny] = 1;
				}
				else if (arr[nx][ny] != landnum
					&& arr[nx][ny] > 0)
				{
					return len;
				}
			}
		}
	}
	return 123456789;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1 && !visit[i][j]) {
				lcnt++;
				BFS(i, j);
			}
		}
	}
	int ans = 123456789;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > 0)
			{
				ans = min(ans, BFS2(i, j));
			}
		}
	}
	cout << ans;
}