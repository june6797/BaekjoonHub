#include <iostream>
#include <queue>
using namespace std;

int arr[11][11];
int visit[10][10];
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
int landcount[100];
queue<pair<int, int>> q;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
	greater<pair<int, pair<int, int>>>> pq;

void BFS(int x, int y, int cnt) {
	visit[x][y] = 1;
	arr[x][y] = cnt;
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
			if (visit[nx][ny] == 0 && arr[nx][ny] == 1)
			{
				visit[nx][ny] = 1;
				arr[nx][ny] = cnt;
				q.push({ nx, ny });
			}
		}
	}
}

void mb(int x, int y, int N, int M) {
	int mylandnum = arr[x][y];
	int count = 0;
	int nx = x;
	int ny = y;
	while (nx--)
	{
		if (nx < 0 || arr[nx][ny] == mylandnum)
		{
			break;
		}
		if (arr[nx][ny] == 0)
		{
			count++;
		}
		else
		{
			if (count > 1)
			{
				pq.push({ count, { mylandnum, arr[nx][ny] } });
				break;
			}
			else
			{
				break;
			}
		}
	}
	count = 0;
	nx = x;
	ny = y;
	while (nx++)
	{
		if (nx >= N || arr[nx][ny] == mylandnum)
		{
			break;
		}
		if (arr[nx][ny] == 0)
		{
			count++;
		}
		else
		{
			if (count > 1)
			{
				pq.push({ count, { mylandnum, arr[nx][ny] } });
				break;
			}
			else
			{
				break;
			}
		}
	}
	count = 0;
	nx = x;
	ny = y;
	while (ny--)
	{
		if (ny < 0 || arr[nx][ny] == mylandnum)
		{
			break;
		}
		if (arr[nx][ny] == 0)
		{
			count++;
		}
		else
		{
			if (count > 1)
			{
				pq.push({ count, { mylandnum, arr[nx][ny] } });
				break;
			}
			else
			{
				break;
			}
		}
	}
	count = 0;
	nx = x;
	ny = y;
	while (ny++)
	{
		if (ny >= M || arr[nx][ny] == mylandnum)
		{
			break;
		}
		if (arr[nx][ny] == 0)
		{
			count++;
		}
		else
		{
			if (count > 1)
			{
				pq.push({ count, { mylandnum, arr[nx][ny] } });
				break;
			}
			else
			{
				break;
			}
		}
	}

}

int find(int a) {
	if (a == landcount[a])
	{
		return a;
	}
	else
	{
		return landcount[a] = find(landcount[a]);
	}
}

void unionfind(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b)
	{
		landcount[b] = a;
	}
}

int main() {
	int N, M, lcnt = 0, ans = 0, ecnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1 && visit[i][j] == 0)
			{
				lcnt++;
				BFS(i, j, lcnt);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] != 0)
			{
				mb(i, j, N, M);
			}
		}
	}
	for (int i = 0; i <= lcnt; i++)
	{
		landcount[i] = i;
	}

	while (!pq.empty())
	{
		int bsize = pq.top().first;
		int bstart = pq.top().second.first;
		int bend = pq.top().second.second;
		pq.pop();
		if (find(bstart) != find(bend))
		{
			unionfind(bstart, bend);
			ans += bsize;
			ecnt++;
		}
	}
	if (ecnt != lcnt - 1 || ans == 0)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
}