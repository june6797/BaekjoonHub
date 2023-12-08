#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[50][50];
int visit[13];
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
vector<pair<int, int>> c;

int cvisit[50][50];
int cdist[50][50];
int N, ans = 1234567890;

void BFS(int x, int y) {
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cvisit[i][j] = 0;
		}
	}
	cvisit[x][y] = 1;
	q.push({ 0, {x, y} });
	while (!q.empty())
	{
		int dist = q.front().first;
		int tx = q.front().second.first;
		int ty = q.front().second.second;
		q.pop();
		if (arr[tx][ty] == 1)
		{
			if (cdist[tx][ty] > dist)
			{
				cdist[tx][ty] = dist;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + x_move[i];
			int ny = ty + y_move[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N
				&& cvisit[nx][ny] == 0)
			{
				cvisit[nx][ny] = 1;
				q.push({ dist + 1, { nx, ny } });
			}
		}
	}
}

void DFS(int start, int d, int m) {
	if (d == m)
	{
		for (int i = 0; i < m; i++)
		{
			arr[c[i].first][c[i].second] = 0;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cdist[i][j] = 1234567890;
			}
		}

		int ta = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 2)
				{
					BFS(i, j);
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 1)
				{
					ta += cdist[i][j];
				}
			}
		}
		if (ans > ta)
		{
			ans = ta;
		}
		for (int i = 0; i < m; i++)
		{
			arr[c[i].first][c[i].second] = 2;
		}
		return;
	}
	for (int i = start; i < v.size(); i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			c.push_back({ v[i].first, v[i].second });
			DFS(i + 1, d + 1, m);
			c.pop_back();
			visit[i] = 0;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M, cnt = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				v.push_back({ i, j });
			}
		}
	}
	DFS(0, 0, v.size() - M);
	cout << ans;
}