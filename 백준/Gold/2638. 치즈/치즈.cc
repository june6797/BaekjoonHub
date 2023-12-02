#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int visit[101][101];
int c[101][101];

int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

void BFS(int x, int y, int n, int m) {
	visit[x][y] = 1;
	q.push({ x, y });
	while (!q.empty())
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + x_move[i];
			int ny = ty + y_move[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m
				&& visit[nx][ny] == 0 && arr[nx][ny] == 0)
			{
				visit[nx][ny] = 1;
				q.push({ nx, ny });
			}
			else if (nx >= 0 && nx < n && ny >= 0 && ny < m
				&& arr[nx][ny] == 1)
			{
				c[nx][ny]++;
			}
		}
	}
}
int main() {
	int N, M, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	while (1)
	{
		bool flag = true;
		BFS(0, 0, N, M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (c[i][j] >= 2)
				{
					flag = false;
					arr[i][j] = 0;
				}
				if (c[i][j] == 1)
				{
					flag = false;
				}
				c[i][j] = 0;
				visit[i][j] = 0;
			}
		}

		if (flag)
		{
			break;
		}
		ans++;
	}
	cout << ans;


}