#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int arr2[101][101];
queue <pair<int, int>> q;
int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

void BFS(int x, int y, int N) {
	arr[x][y] = 0;
	q.push({ x, y });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x_next = x + x_move[i];
			int y_next = y + y_move[i];
			if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < N
				&& arr[x_next][y_next] != 0)
			{
				q.push({ x_next, y_next });
				arr[x_next][y_next] = 0;
			}
		}
	}
}

int main() {
	int N, max = 0, ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
			if (max < arr[i][j])
			{
				max = arr[i][j];
			}
		}
	}


	for (int h = 0; h <= max; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] <= h)
				{
					arr[i][j] = 0;
				}
			}
		}
		int cnt = 0;

		for (int m = 0; m < N; m++)
		{
			for (int n = 0; n < N; n++)
			{
				if (arr[m][n] != 0)
				{
					BFS(m, n, N);
					cnt++;
				}
			}
		}

		if (cnt > ans)
		{
			ans = cnt;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = arr2[i][j];
			}
		}
	}

	cout << ans;
}