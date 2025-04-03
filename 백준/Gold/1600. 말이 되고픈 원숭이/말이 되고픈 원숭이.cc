#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

int k, w, h;
int arr[201][201];
bool visit[201][201][31];
int check[201][201];
int dx[12] = { -1, 0, 1, 0, 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[12] = { 0, 1, 0, -1, 2, 1, -1, -2, -2, -1, 1, 2 };

int BFS(int x, int y) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	visit[x][y][0] = 1;
	q.push({ {x, y}, {k, 0} });
	while (!q.empty())
	{
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int tk = q.front().second.first;
		int tm = q.front().second.second;
		q.pop();
		if (tx == h - 1 && ty == w - 1)
		{
			return tm;
		}

		if (tk > 0)
		{
			for (int i = 0; i < 12; i++)
			{
				int nx = dx[i] + tx;
				int ny = dy[i] + ty;
				if (i < 4)
				{
					if (nx >= 0 && nx < h && ny >= 0 && ny < w
						&& !visit[nx][ny][k - tk] && arr[nx][ny] == 0)
					{
						visit[nx][ny][k - tk] = 1;
						q.push({ {nx, ny}, {tk, tm + 1} });
					}
				}
				else
				{
					if (nx >= 0 && nx < h && ny >= 0 && ny < w
						&& !visit[nx][ny][k - tk + 1] && arr[nx][ny] == 0)
					{
						visit[nx][ny][k - tk + 1] = 1;
						q.push({ {nx, ny}, {tk - 1, tm + 1} });
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + tx;
				int ny = dy[i] + ty;
				if (nx >= 0 && nx < h && ny >= 0 && ny < w
					&& !visit[nx][ny][k - tk] && arr[nx][ny] == 0)
				{
					visit[nx][ny][k - tk] = 1;
					q.push({ {nx, ny}, {tk, tm + 1} });
				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << BFS(0, 0);
}