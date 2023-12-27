#include <iostream>
using namespace std;

long long int dp[45][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int K;
	cin >> K;
	dp[0][0] = 1;
	for (int i = 1; i <= K; i++)
	{
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
	}
	cout << dp[K][0] << " " << dp[K][1];
}