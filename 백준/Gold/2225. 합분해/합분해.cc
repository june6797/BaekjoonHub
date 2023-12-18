#include <iostream>
using namespace std;

int dp[201][201];
int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		dp[i][1] = 1;
	}
	for (int i = 1; i <= K; i++)
	{
		dp[1][i] = i;
	}
	for (int i = 2; i <= K; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			dp[j][i] = (dp[j - 1][i] + dp[j][i - 1]) % 1000000000;
		}
	}
	cout << dp[N][K];
}