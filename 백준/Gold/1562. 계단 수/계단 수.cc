#include <iostream>
#define mod 1000000000
using namespace std;

int dp[101][10][1 << 10];
int main() {
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i][1 << i] = 1;
	}
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k < (1 << 10); k++)
			{
				if (j == 0)
				{
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j + 1][k]) % mod;
				}
				else if (j == 9)
				{
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j - 1][k]) % mod;
				}
				else
				{
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j + 1][k]) % mod;
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j - 1][k]) % mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans = (ans + dp[N][i][(1 << 10) - 1]) % 1000000000;
	}
	cout << ans;
}