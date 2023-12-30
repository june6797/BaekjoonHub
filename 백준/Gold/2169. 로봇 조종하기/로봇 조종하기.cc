#include <iostream>
using namespace std;

int dp[1001][1001];
int cost[1001][1001];
int temp[1001][1001][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> cost[i][j];
		}
	}
	for (int i = 1; i <= M; i++)
	{
		dp[1][i] = dp[1][i - 1] + cost[1][i];
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			temp[i][j][0] = dp[i - 1][j] + cost[i][j];
			temp[i][j][1] = dp[i - 1][j] + cost[i][j];
		}
		for (int j = 2; j <= M; j++)
		{
			temp[i][j][0] = max(temp[i][j][0], temp[i][j - 1][0] + cost[i][j]);
		}
		for (int j = M - 1; j >= 1; j--)
		{
			temp[i][j][1] = max(temp[i][j][1], temp[i][j + 1][1] + cost[i][j]);
		}
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = max(temp[i][j][0], temp[i][j][1]);
		}
	}
	cout << dp[N][M];
}