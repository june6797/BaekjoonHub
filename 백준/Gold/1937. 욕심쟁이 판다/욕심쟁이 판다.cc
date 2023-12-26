#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[501][501];
int dp[501][501];
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };

int DFS(int x, int y, int N) {
	if (dp[x][y] != 0)
	{
		return dp[x][y];
	}
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + x_move[i];
		int ny = y + y_move[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N
			&& arr[nx][ny] > arr[x][y])
		{
			dp[x][y] = max(dp[x][y], DFS(nx, ny, N) + 1);
		}
	}
	return dp[x][y];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			DFS(i, j, N);
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}