#include <iostream>
using namespace std;

int dp[501];
int temp[501];
int main() {
	int n, ans = -1;
	cin >> n;
	dp[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int num;
			cin >> num;
			if (j == 1)
			{
				temp[1] = dp[1] + num;
			}
			else if (j == i)
			{
				temp[j] = dp[j - 1] + num;
			}
			else
			{
				temp[j] = max(dp[j - 1] + num, dp[j] + num);
			}
		}
		for (int k = 1; k <= i; k++)
		{
			dp[k] = temp[k];
		}

	}
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;
}