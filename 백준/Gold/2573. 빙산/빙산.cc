#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

int arr[301][301];
bool check[301][301];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;
void BFS(int x, int y) {
	check[x][y] = 1;
	queue<pair<int, int>> q;
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
			if (nx >= 0 && nx < n && ny >= 0 && ny < m
				&& arr[nx][ny] > 0 && check[nx][ny] == 0)
			{
				check[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] > 0 && check[i][j] == 0)
			{
				cnt++;
				BFS(i, j);
			}
		}
	}
	int ans = 1;
	while (true)
	{
		int tempcnt = 0;
		memset(check, 0, sizeof(check));
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] > 0)
				{
					flag = true;
					break;
				}
			}
		}
		if (!flag)
		{
			cout << 0;
			exit(0);
		}
		int temparr[301][301] = { 0, };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] > 0)
				{
					int minuscnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int di = i + dx[k];
						int dj = j + dy[k];
						if (di >= 0 && di < n && dj >= 0 && dj < m
							&& arr[di][dj] == 0)
						{
							minuscnt++;
						}
					}
					temparr[i][j] = minuscnt;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = max(arr[i][j] - temparr[i][j], 0);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] > 0 && check[i][j] == 0)
				{
					tempcnt++;
					BFS(i, j);
				}
			}
		}
		if (tempcnt > cnt)
		{
			cout << ans << "\n";
			break;
		}
		ans++;
	}

}