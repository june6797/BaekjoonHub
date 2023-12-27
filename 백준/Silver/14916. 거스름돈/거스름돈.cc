#include <iostream>
using namespace std;

int dp[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	dp[1] = 987654321;
	dp[2] = 1;
	dp[3] = 987654321;
	dp[4] = 2;
	for (int i = 5; i <= n; i++)
	{
		dp[i] = min(dp[i - 5] + 1, dp[i - 2] + 1);
	}
	if (dp[n] == 987654321)
	{
		cout << "-1";
	}
	else
	{
		cout << dp[n];
	}
}