#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;

int r, c;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char arr[1001][1001];
bool visit[1001][1001];
queue<pair<pair<int, int>, pair<char, int>>> q;

int BFS() {
	while (!q.empty())
	{
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		char k = q.front().second.first;
		int tt = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c
				&& k == 'F' && !visit[nx][ny] &&
				(arr[nx][ny] == '.' || arr[nx][ny] == 'J'))
			{
				visit[nx][ny] = 1;
				q.push({ {nx, ny}, {'F', 0} });
			}
			if (k == 'J' && (nx < 0 || nx >= r
				|| ny < 0 || ny >= c)) {
				return tt + 1;
			}
			if (k == 'J' && nx >= 0 && nx < r
				&& ny >= 0 && ny < c && !visit[nx][ny] &&
				arr[nx][ny] == '.') {
				visit[nx][ny] = 1;
				q.push({ {nx, ny}, {'J', tt + 1} });
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;
	int sx = 0, sy = 0;
	for (int i = 0; i < r; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			arr[i][j] = str[j];
			if (str[j] == '#')
			{
				visit[i][j] = 1;
			}
			else if (str[j] == 'J')
			{
				sx = i;
				sy = j;
			}
			else if (str[j] == 'F') {
				q.push({ {i, j}, {'F', 0} });
				visit[i][j] = 1;
			}
		}
	}
	q.push({ {sx, sy}, {'J', 0} });
	visit[sx][sy] = 1;
	int ans = BFS();
	if (ans == 0) {
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << ans;
	}

}