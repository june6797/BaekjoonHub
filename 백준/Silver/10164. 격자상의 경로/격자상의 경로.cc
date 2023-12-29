#include <iostream>
using namespace std;

long long int dp[16][16];
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	dp[0][1] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	if (K == 0)
	{
		cout << dp[N][M];
	}
	else
	{
		int d = (K - 1) / M + 1;
		int r = K % M;
		if (r == 0)
		{
			r = M;
		}
		int first = dp[d][r];
		int second = dp[N - d + 1][M - r + 1];
		cout << first * second;
	}
}