#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <queue>
typedef long long int ll;
using namespace std;

struct marble
{
	int rx, ry, bx, by, cnt;
};
char arr[11][11];
int visit[11][11][11][11];
int N, M;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
queue<marble> q;

int BFS() {
	int ans = -1;
	while (!q.empty())
	{
		marble temp = q.front();
		q.pop();
		if (temp.cnt > 10)
		{
			break;
		}
		if (arr[temp.rx][temp.ry] == 'O' && arr[temp.bx][temp.by] != 'O')
		{
			ans = temp.cnt;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nrx = temp.rx;
			int nry = temp.ry;
			int nbx = temp.bx;
			int nby = temp.by;
			while (1)
			{
				if (arr[nrx][nry] != 'O' && arr[nrx][nry] != '#')
				{
					nrx += dx[i];
					nry += dy[i];
				}
				else
				{
					if (arr[nrx][nry] == '#')
					{
						nrx -= dx[i];
						nry -= dy[i];
					}
					break;
				}
			}
			while (1)
			{
				if (arr[nbx][nby] != 'O' && arr[nbx][nby] != '#')
				{
					nbx += dx[i];
					nby += dy[i];
				}
				else
				{
					if (arr[nbx][nby] == '#')
					{
						nbx -= dx[i];
						nby -= dy[i];
					}
					break;
				}
			}
			if (nrx == nbx && nry == nby)
			{
				if (arr[nrx][nry] != 'O')
				{
					int rd = abs(nrx - temp.rx) + abs(nry - temp.ry);
					int bd = abs(nbx - temp.bx) + abs(nby - temp.by);
					if (rd < bd)
					{
						nbx -= dx[i];
						nby -= dy[i];
					}
					else
					{
						nrx -= dx[i];
						nry -= dy[i];
					}
				}
			}
			if (visit[nrx][nry][nbx][nby] == 0)
			{
				visit[nrx][nry][nbx][nby] = 1;
				q.push({ nrx, nry, nbx, nby, temp.cnt + 1 });
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int rx = 0, ry = 0, bx = 0, by = 0;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
			if (str[j] == 'R')
			{
				rx = i;
				ry = j;
			}
			if (str[j] == 'B')
			{
				bx = i;
				by = j;
			}
		}
	}
	q.push({ rx, ry, bx, by, 0 });
	visit[rx][ry][bx][by] = 1;
	cout << BFS();
}
