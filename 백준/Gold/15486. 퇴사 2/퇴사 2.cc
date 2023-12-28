#include <iostream>
using namespace std;

int T[1500002];
int P[1500002];
int dp[1500002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> T[i] >> P[i];
	}
	int ans = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		dp[i] = max(dp[i], dp[i - 1]);
		if (T[i] + i <= n + 1)
		{
			dp[T[i] + i] = max(dp[T[i] + i], dp[i] + P[i]);
		}
	}
	cout << dp[n + 1];
}