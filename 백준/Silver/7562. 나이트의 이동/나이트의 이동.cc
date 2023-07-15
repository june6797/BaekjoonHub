#include <iostream>
#include <queue>
using namespace std;

int chess[301][301];
int ans[301][301];
int x_move[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int y_move[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
queue<pair<int, int>> q;

void bfs(int x, int y, int dx, int dy, int l) {
	chess[x][y] = 1;
	ans[x][y] = 0;
	q.push({ x, y });
	while (q.front().first != dx || q.front().second != dy)
	{
		int x_new = q.front().first;
		int y_new = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int x_next = x_new + x_move[i];
			int y_next = y_new + y_move[i];
			if (x_next >= 0 && x_next < l && y_next >= 0 && y_next < l
				&& chess[x_next][y_next] == 0)
			{
				ans[x_next][y_next] = ans[x_new][y_new] + 1;
				chess[x_next][y_next] = 1;
				q.push({ x_next, y_next });
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int l, x, y, dx, dy;
		cin >> l;
		cin >> x >> y;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				chess[i][j] = 0;
				ans[i][j] = 0;
			}
		}
		while (!q.empty())
		{
			q.pop();
		}
		cin >> dx >> dy;
		bfs(x, y, dx, dy, l);
		cout << ans[dx][dy] << "\n";
	}
}