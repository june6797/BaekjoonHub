#include <iostream>
#include <climits>
using namespace std;

long long int dp[100001][5][5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int p[5][5] = { {0, 2, 2, 2, 2}, {2, 1, 3, 4, 3},
		{2, 3, 1, 3, 4}, {2, 4, 3, 1, 3}, {2, 3, 4, 3, 1} };
	int s = 1;
	for (int i = 0; i < 100001; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				dp[i][j][k] = 10000000;
			}
		}
	}
	dp[0][0][0] = 0;
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (n == i)
				{
					continue;
				}
				for (int j = 0; j < 5; j++)
				{
					dp[s][i][n] = min(dp[s - 1][i][j] + p[j][n], dp[s][i][n]);
				}
			}
			for (int j = 0; j < 5; j++)
			{
				if (n == j)
				{
					continue;
				}
				for (int i = 0; i < 5; i++)
				{
					dp[s][n][j] = min(dp[s - 1][i][j] + p[i][n], dp[s][n][j]);
				}
			}
		}
		s++;
	}
	s--;
	long long int ans = LONG_MAX;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			ans = min(ans, dp[s][i][j]);
		}
	}
	cout << ans;
}