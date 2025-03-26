#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, m;
char arr[51][51];
bool visit[51][51];
int ans = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void BFS(int x, int y) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = 0;
		}
	}
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y }, 0 });
	visit[x][y] = 1;
	while (!q.empty())
	{
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int cnt = q.front().second;
		ans = max(ans, cnt);
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m
				&& visit[nx][ny] == false && arr[nx][ny] == 'L')
			{
				visit[nx][ny] = 1;
				q.push({ { nx, ny }, cnt + 1 });
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'L')
			{
				BFS(i, j);
			}
		}
	}
	cout << ans;
}