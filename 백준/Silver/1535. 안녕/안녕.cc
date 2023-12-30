#include <iostream>
using namespace std;

int L[21];
int J[21];
int dp[21][101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> L[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> J[i];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (j - L[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - L[i]] + J[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << dp[N][99];
}