#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

int n, m;
int ans;
char arr[12][6];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[12][6];
int BFS(int x, int y) {
	vector<pair<int, int>> v;
	int ret = 1;
	char temp = arr[x][y];
	visit[x][y] = 1;
	queue<pair<int, int>> q;
	v.push_back({ x, y });
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
			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6
				&& !visit[nx][ny] && arr[nx][ny] == temp)
			{
				v.push_back({ nx, ny });
				visit[nx][ny] = 1;
				ret++;
				q.push({ nx, ny });
			}
		}
	}
	if (ret >= 4)
	{
		for (int i = 0; i < v.size(); i++)
		{
			arr[v[i].first][v[i].second] = '.';
		}
	}
	return ret;
}

void godown() {
	for (int i = 0; i < 6; i++)
	{
		vector<char> temp;
		for (int j = 11; j >= 0; j--)
		{
			if (arr[j][i] != '.')
			{
				temp.push_back(arr[j][i]);
			}
		}
		for (int j = 0; j < temp.size(); j++)
		{
			arr[11 - j][i] = temp[j];
		}
		for (int j = temp.size(); j < 12; j++)
		{
			arr[11 - j][i] = '.';
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 12; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 6; j++)
		{
			arr[i][j] = str[j];
		}
	}
	while (true)
	{
		bool check = true;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (arr[i][j] != '.' && !visit[i][j])
				{
					int cnt = BFS(i, j);
					if (cnt >= 4)
					{
						check = false;
					}
				}
			}
		}
		if (check)
		{
			break;
		}

		ans++;
		godown();

		memset(visit, 0, sizeof(visit));
	}
	cout << ans;
}
