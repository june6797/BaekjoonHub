#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1234567890
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m;
int arr[101][101];
int temp[101][101];
bool visited[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(int x, int y) {
	queue<pii> q;
	vector<pii> v;
	q.push({ x, y });
	visited[x][y] = 1;
	while (!q.empty())
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (visited[nx][ny] == 0)
				{
					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
				else if (arr[nx][ny] == 1)
				{
					v.push_back({ nx, ny });
				}
			}
		}

		for (int i = 0; i < v.size(); i++)
		{
			arr[v[i].first][v[i].second] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int hour = 0;
	int ans = 0;
	while (true)
	{
		int tempans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				visited[i][j] = arr[i][j];
				if (arr[i][j] == 1)
				{
					tempans++;
				}
			}
		}
		ans = tempans;

		bfs(0, 0);
		hour++;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1)
				{
					cnt++;
				}
			}
		}
		if (cnt == 0)
		{
			cout << hour << "\n";
			break;
		}
	}
	cout << ans;
}