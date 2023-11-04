#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
int arr[1001][1001];
int visit[1001][1001][2];
int ans[1001][1001][2];
queue<tuple<int, int, int >> q;



void BFS(int x, int y, int z, int N, int M) {
	visit[x][y][z] = 1;
	q.push({ x, y, z });
	while (!q.empty())
	{
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();
		if (a == N - 1 && b == M - 1)
		{
			cout << ans[a][b][c] + 1 << "\n";
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = a + x_move[i];
			int ny = b + y_move[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M
				&& visit[nx][ny][c] == 0)
			{
				if (arr[nx][ny] == 0)
				{
					if (c == 0)
					{
						visit[nx][ny][c] = 1;
						ans[nx][ny][c] = ans[a][b][c] + 1;
						q.push({ nx, ny, c });
					}
					else
					{
						visit[nx][ny][c] = 1;
						ans[nx][ny][c] = ans[a][b][c] + 1;
						q.push({ nx, ny, c });
					}
				}
				else
				{
					if (c == 0)
					{
						visit[nx][ny][c] = 1;
						ans[nx][ny][c + 1] = ans[a][b][c] + 1;
						q.push({ nx, ny, c + 1 });
					}
					else
					{

					}
				}
			}
		}
	}
	cout << "-1\n";

}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}
	BFS(0, 0, 0, N, M);
}
