#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

int n, m, d, ans, ret;
int arr[21][21];
int firstarr[21][21];
bool visit[21][21];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

pair<int, int> BFS(int x, int y) {
	visit[x][y] = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x ,y }, 0 });
	while (!q.empty())
	{
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int move = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx >= 0 && nx <= n && ny >= 0 && ny < m
				&& !visit[nx][ny] && move < d)
			{
				if (arr[nx][ny] == 1)
				{
					return { nx,ny };
				}
				visit[nx][ny] = 1;
				q.push({ { nx, ny }, move + 1 });
			}
		}
	}
	return { -1, -1 };
}

void visitreset() {
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = 0;
		}
	}
}

bool checkenemy() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				return false;
			}
		}
	}
	return true;
}

void moveenemy() {
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = arr[i - 1][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		arr[0][i] = 0;
	}
}
void make_seat(int a, int b, int c) {
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = firstarr[i][j];
		}
	}
	while (true)
	{
		if (checkenemy())
		{
			break;
		}
		pair<int, int> fx = BFS(n, a);
		visitreset();
		pair<int, int> sx = BFS(n, b);
		visitreset();
		pair<int, int> tx = BFS(n, c);
		visitreset();
		if (fx.first != -1)
		{
			arr[fx.first][fx.second] = 0;
			ans++;
		}
		if (sx.first != -1 && arr[sx.first][sx.second] == 1)
		{
			arr[sx.first][sx.second] = 0;
			ans++;
		}
		if (tx.first != -1 && arr[tx.first][tx.second] == 1)
		{
			arr[tx.first][tx.second] = 0;
			ans++;
		}

		moveenemy();
	}
	ret = max(ret, ans);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			firstarr[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < m - 2; i++)
	{
		for (int j = i + 1; j < m - 1; j++)
		{
			for (int k = j + 1; k < m; k++)
			{
				make_seat(i, j, k);
			}
		}
	}
	cout << ret;
}
