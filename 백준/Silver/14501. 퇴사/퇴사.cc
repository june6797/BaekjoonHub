#include <iostream>
using namespace std;
int arr[2][17];
int dp[17];
int main() {
	int N, ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[0][i];
		cin >> arr[1][i];
	}

	for (int i = 1; i <= N + 1; i++)
	{
		dp[i] = max(dp[i], ans);
		int f = i + arr[0][i];
		if (f <= N + 1)
		{
			dp[f] = max(dp[f], arr[1][i] + dp[i]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
