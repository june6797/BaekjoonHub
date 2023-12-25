#include <iostream>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < M; i++)
	{
		dp[0][i] = dp[0][i - 1] + arr[0][i];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i - 1][j - 1] + arr[i][j]);
				dp[i][j] = max(dp[i][j - 1] + arr[i][j], dp[i][j]);
			}
		}
	}
	cout << dp[N - 1][M - 1];
}