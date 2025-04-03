#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

int n, m, k, ans;
int arr[101][101];
bool visit[101][101];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int x, int y) {
	int k = 1;
	queue<pair<int, int>> q;
	visit[x][y] = 1;
	q.push({ x, y });
	while (!q.empty())
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
				&& !visit[nx][ny] && arr[nx][ny] == 1)
			{
				k++;
				visit[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
	ans = max(ans, k);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 1 && !visit[i][j])
			{
				BFS(i, j);
			}
		}
	}
	cout << ans;
}
