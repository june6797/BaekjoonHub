#include <iostream>
#include <queue>
using namespace std;

int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
int arr[50][50];
int visit[50][50];
int ans[50][50];
queue<pair<int, int>> q;

void BFS(int x, int y, int N, int check, int L, int R) {
	queue<pair<int, int>> vq;

	visit[x][y] = 1;

	q.push({ x, y });

	vq.push({ x, y });
	int vn = 1, sum = arr[x][y];

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = a + x_move[i];
			int ny = b + y_move[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N
				&& visit[nx][ny] == 0)
			{
				if (abs(arr[nx][ny] - arr[a][b]) >= L
					&& abs(arr[nx][ny] - arr[a][b]) <= R)
				{
					visit[nx][ny] = 1;
					q.push({ nx, ny });
					vq.push({ nx, ny });
					vn++;
					sum += arr[nx][ny];
				}
			}
		}
	}
	int f = sum / vn;
	while (!vq.empty())
	{
		ans[vq.front().first][vq.front().second] = f;
		vq.pop();
	}
}

int main() {
	int N, L, R;
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	int check = 0, ra = 0;

	while (check != N * N)
	{
		check = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == 0)
				{
					check++;
					BFS(i, j, N, check, L, R);
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				visit[i][j] = 0;
				arr[i][j] = ans[i][j];
				ans[i][j] = 0;
			}
		}
		ra++;
	}
	cout << ra - 1;
}
