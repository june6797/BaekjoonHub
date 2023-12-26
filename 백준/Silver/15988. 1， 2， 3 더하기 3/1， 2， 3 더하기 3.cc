#include <iostream>
using namespace std;

long long int dp[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++)
	{
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
	}
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}