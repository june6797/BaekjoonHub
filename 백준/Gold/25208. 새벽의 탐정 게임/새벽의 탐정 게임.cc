#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <regex>

#define mod 1000000007;
typedef long long int ll;

using namespace std;
char arr[501][501];
bool visit[501][501][6];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int x, y;

int cal(int dir, int i) {
	switch (dir)
	{
	case 0:
		if (i == 0)
		{
			return 2;
		}
		else if (i == 1)
		{
			return 3;
		}
		else if (i == 2)
		{
			return 4;
		}
		else if (i == 3)
		{
			return 1;
		}
		break;
	case 1:
		if (i == 0)
		{
			return 1;
		}
		else if (i == 1)
		{
			return 0;
		}
		else if (i == 2)
		{
			return 1;
		}
		else if (i == 3)
		{
			return 5;
		}
		break;
	case 2:
		if (i == 0)
		{
			return 5;
		}
		else if (i == 1)
		{
			return 2;
		}
		else if (i == 2)
		{
			return 0;
		}
		else if (i == 3)
		{
			return 2;
		}
		break;
	case 3:

		if (i == 0)
		{
			return 3;
		}
		else if (i == 1)
		{
			return 5;
		}
		else if (i == 2)
		{
			return 3;
		}
		else if (i == 3)
		{
			return 0;
		}
		break;
	case 4:
		if (i == 0)
		{
			return 0;
		}
		else if (i == 1)
		{
			return 4;
		}
		else if (i == 2)
		{
			return 5;
		}
		else if (i == 3)
		{
			return 4;
		}
		break;
	case 5:
		if (i == 0)
		{
			return 4;
		}
		else if (i == 1)
		{
			return 1;
		}
		else if (i == 2)
		{
			return 2;
		}
		else if (i == 3)
		{
			return 3;
		}
		break;
	default:
		break;
	}
}
void solve(int x, int y) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { x, y }, {0, 0} });
	visit[x][y][0] = 1;
	while (!q.empty())
	{
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int dir = q.front().second.first;
		int dep = q.front().second.second;
		if (arr[tx][ty] == 'R' && dir == 0)
		{
			cout << q.front().second.second;
			exit(0);
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			int ndir = cal(dir, i);
			if (arr[nx][ny] != '#' && visit[nx][ny][ndir] == false)
			{
				if (arr[nx][ny] == 'R' && ndir != 0)
				{
					continue;
				}
				visit[nx][ny][ndir] = true;
				q.push({ {nx, ny}, {ndir, dep + 1} });
			}
		}
	}
	cout << -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = str[j];
			if (arr[i][j] == 'D')
			{
				x = i;
				y = j;
			}
		}
	}
	solve(x, y);
}