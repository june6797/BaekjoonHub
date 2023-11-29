#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
int visit[1001][1001];
int ans[1001][1001];
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

void BFS(int x, int y, int N, int M) {
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
			if (nx < N && nx >= 0 && ny < M && ny >= 0 &&
				visit[nx][ny] == 0 && arr[nx][ny] == 1)
			{
				visit[nx][ny] = 1;
				ans[nx][ny] = ans[tx][ty] + 1;
				q.push({ nx, ny });
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ans[i][j] == 0 && arr[i][j] == 1)
			{
				cout << "-1 ";
			}
			else
			{
				cout << ans[i][j] << " ";
			}
		}
		cout << "\n";
	}



}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, x, y;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				x = i;
				y = j;
			}
		}
	}
	BFS(x, y, N, M);


}