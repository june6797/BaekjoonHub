#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int arr[51][51];
int dp[51][51];
bool visit[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int N, M;
int DFS(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M || arr[x][y] == 0)
	{
		return 0;
	}
	if (visit[x][y])
	{
		cout << "-1" << "\n";
		exit(0);
	}
	if (dp[x][y])
	{
		return dp[x][y];
	}
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + (arr[x][y] * dx[i]);
		int ny = y + (arr[x][y] * dy[i]);
		dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
	}
	visit[x][y] = 0;
	return dp[x][y];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == 'H')
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = str[j] - '0';
			}
		}
	}
	cout << DFS(0, 0);
}