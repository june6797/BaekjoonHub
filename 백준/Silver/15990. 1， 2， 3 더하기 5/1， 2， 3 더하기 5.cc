#include <iostream>

#define M 1000000009;

using namespace std;

long long int dp[100001][3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	dp[1][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	for (int i = 4; i <= 100000; i++)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % M;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % M;
		dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % M;
	}
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 1000000009 << "\n";
	}
}