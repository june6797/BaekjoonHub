#include <iostream>
using namespace std;

int dp[1001][31][2];
int t[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, W;
	cin >> T >> W;
	for (int i = 1; i <= T; i++)
	{
		cin >> t[i];
	}
	int ans = 0;
	for (int i = 0; i <= W; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if (i == 0)
			{
				if (t[j] == 1)
				{
					dp[j][i][0] = dp[j - 1][i][0] + 1;
				}
				else
				{
					dp[j][i][0] = dp[j - 1][i][0];
				}
			}
			else
			{
				if (t[j] == 1)
				{
					dp[j][i][0] = max(dp[j - 1][i][0] + 1, dp[j - 1][i - 1][1] + 1);
					dp[j][i][1] = max(dp[j - 1][i][1], dp[j - 1][i - 1][0]);
				}
				else
				{
					dp[j][i][0] = max(dp[j - 1][i][0], dp[j - 1][i - 1][1]);
					dp[j][i][1] = max(dp[j - 1][i][1] + 1, dp[j - 1][i - 1][0] + 1);
				}
			}
			ans = max(ans, dp[j][i][0]);
			ans = max(ans, dp[j][i][1]);
		}
	}
	cout << ans;
}