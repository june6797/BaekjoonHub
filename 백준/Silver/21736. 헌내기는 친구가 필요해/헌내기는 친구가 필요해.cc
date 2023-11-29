#include <iostream>
#include <queue>
using namespace std;

int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

char arr[601][601];
int visit[601][601];
void BFS(int x, int y, int N, int M) {
	int ans = 0;
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
				visit[nx][ny] == 0 && (arr[nx][ny] == 'O'
					|| arr[nx][ny] == 'P'))
			{
				if (arr[nx][ny] == 'P')
				{
					ans++;
				}
				visit[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
	if (ans == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << ans;
	}
}
int main()
{
	int N, M, x, y;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'I')
			{
				x = i;
				y = j;
			}
		}
	}
	BFS(x, y, N, M);
}