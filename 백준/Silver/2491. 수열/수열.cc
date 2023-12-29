#include <iostream>
using namespace std;

int num[100001];
int dp[100001][2];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (num[i] == num[i - 1])
		{
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1] + 1;
		}
		else if (num[i] > num[i - 1])
		{
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = 1;
		}
		else if (num[i] < num[i - 1])
		{
			dp[i][0] = 1;
			dp[i][1] = dp[i - 1][1] + 1;
		}
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
	}
	cout << ans;
}