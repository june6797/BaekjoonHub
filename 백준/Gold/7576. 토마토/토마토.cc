#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int tarr[1001][1001];
queue<pair<int, int>> q;

int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

void DFS(int N, int M) {
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x_new = x + x_move[i];
			int y_new = y + y_move[i];

			if ((x_new >= 0 && x_new < N) && (y_new >= 0 && y_new < M)
				&& tarr[x_new][y_new] == 0) {

				q.push({ x_new, y_new });
				tarr[x_new][y_new] = tarr[x][y] + 1;
			}
		}
	}
}



int main() {
	int M, N, num, ans = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			tarr[i][j] = num;
			if (num == 1)
			{
				q.push({ i, j });
			}
		}
	}

	DFS(N, M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tarr[i][j] == 0)
			{
				cout << "-1";
				return 0;
			}
			if (ans < tarr[i][j])
			{
				ans = tarr[i][j];
			}
		}
	}
	cout << ans - 1;
	return 0;
}
