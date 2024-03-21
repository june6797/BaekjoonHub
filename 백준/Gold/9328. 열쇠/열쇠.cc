#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <queue>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
queue<pair<int, int>> q;
queue<pair<int, int>> dq[26];
int key[26];
char arr[102][102];
int visit[102][102];
int ans, h, w;

void DFS(int x, int y) {
	visit[x][y] = 1;
	q.push({ x, y });
	while (!q.empty())
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx >= 0 && nx <= h + 1 && ny >= 0 && ny <= w + 1
				&& visit[nx][ny] == 0 && arr[nx][ny] != '*')
			{
				visit[nx][ny] = 1;
				if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z')
				{
					key[arr[nx][ny] - 'a'] = 1;
					while (!dq[arr[nx][ny] - 'a'].empty())
					{
						q.push({ dq[arr[nx][ny] - 'a'].front().first,
							dq[arr[nx][ny] - 'a'].front().second });
						dq[arr[nx][ny] - 'a'].pop();
					}
					q.push({ nx, ny });
				}
				else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z')
				{
					int keyidx = arr[nx][ny] + 32 - 'a';
					if (key[keyidx] == 0)
					{
						dq[keyidx].push({ nx, ny });
					}
					else
					{
						q.push({ nx, ny });
					}
				}
				else if (arr[nx][ny] == '$')
				{
					ans++;
					q.push({ nx, ny });
				}
				else
				{
					q.push({ nx, ny });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> h >> w;
		memset(arr, '0', sizeof(arr));
		memset(key, 0, sizeof(key));
		memset(visit, 0, sizeof(visit));
		ans = 0;
		q = queue<pair<int, int>>();
		for (int i = 0; i < 26; i++)
		{
			while (!dq[i].empty())
			{
				dq[i].pop();
			}
		}
		for (int i = 1; i <= h; i++)
		{
			string str;
			cin >> str;
			for (int j = 1; j <= w; j++)
			{
				arr[i][j] = str[j - 1];
			}
		}
		string kk;
		cin >> kk;
		if (kk != "0")
		{
			for (int i = 0; i < kk.size(); i++)
			{
				key[kk[i] - 'a'] = 1;
			}
		}
		DFS(0, 0);
		cout << ans << "\n";
	}
}