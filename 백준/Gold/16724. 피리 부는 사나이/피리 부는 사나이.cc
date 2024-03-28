#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int arr[1001][1001];
int visit[1001][1001];
pair<int, int> parent[1001][1001];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

pair<int, int> find(pair<int, int> x) {
	if (x == parent[x.first][x.second])
	{
		return x;
	}
	else
	{
		return parent[x.first][x.second] = find(parent[x.first][x.second]);
	}
}

void uni(pair<int, int> x, pair<int, int> y) {
	x = find(x);
	y = find(y);
	if (x != y)
	{
		parent[y.first][y.second] = x;
	}
}
void DFS(int x, int y) {
	visit[x][y] = 1;
	int nx = x + dx[arr[x][y]];
	int ny = y + dy[arr[x][y]];
	if (visit[nx][ny] == 0)
	{
		pair<int, int> p = { nx, ny };
		DFS(nx, ny);
		uni({ x, y }, p);
	}
	uni({ x, y }, { nx, ny });
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			parent[i][j] = { i, j };
			if (str[j] == 'U')
			{
				arr[i][j] = 0;
			}
			else if (str[j] == 'R')
			{
				arr[i][j] = 1;
			}
			else if (str[j] == 'D')
			{
				arr[i][j] = 2;
			}
			else if (str[j] == 'L')
			{
				arr[i][j] = 3;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 0)
			{
				DFS(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (parent[i][j] == pair<int, int>{i, j})
			{
				ans++;
			}
		}
	}
	cout << ans;
}