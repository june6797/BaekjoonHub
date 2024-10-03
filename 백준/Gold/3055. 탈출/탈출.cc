#include <bits/stdc++.h>
#define mod 1000000007;
#define INF 1234567890;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char arr[51][51];
int n, m;
queue<pair<pair<int, int>, int>> q;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void solve() {
	while (!q.empty())
	{

		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int dep = q.front().second;
		q.pop();
		if (arr[tx][ty] == 'D')
		{
			cout << dep;
			return;
		}
		if (arr[tx][ty] == '*')
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = tx + dx[i];
				int ny = ty + dy[i];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
					&& arr[nx][ny] == '.')
				{
					arr[nx][ny] = '*';
					q.push({ { nx, ny }, dep + 1 });
				}
			}
		}
		if (arr[tx][ty] == 'S')
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = tx + dx[i];
				int ny = ty + dy[i];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
					&& arr[nx][ny] == '.')
				{
					arr[nx][ny] = 'S';
					q.push({ { nx, ny }, dep + 1 });
				}
				else if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
					&& arr[nx][ny] == 'D')
				{
					q.push({ { nx, ny }, dep + 1 });
				}
			}
		}
	}
	cout << "KAKTUS";
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int sx = 0, sy = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '*')
			{
				q.push({ { i, j }, 0 });
			}
			if (arr[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
		}
	}
	q.push({ { sx, sy }, 0 });
	solve();

}
