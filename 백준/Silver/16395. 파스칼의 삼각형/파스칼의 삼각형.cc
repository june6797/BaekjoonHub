#include <iostream>
using namespace std;

int dp[31][31];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	dp[1][0] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j == 0 || j == N - 1)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K - 1];
}