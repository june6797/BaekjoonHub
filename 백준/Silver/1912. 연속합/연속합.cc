#include <iostream>
#include <climits>
using namespace std;

int dp[100001];

int main() {
	int n, num, ans = INT_MIN;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		if (dp[i - 1] + num > 0)
		{
			dp[i] = dp[i - 1] + num;
			ans = max(ans, dp[i - 1] + num);
		}
		else
		{
			ans = max(ans, dp[i - 1] + num);
		}
	}
	cout << ans;
}