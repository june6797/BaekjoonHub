#include <iostream>
#include <climits>
using namespace std;

int dp[10001];
int coin[101];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		coin[i] = num;
	}
	for (int i = 1; i <= k; i++)
	{
		dp[i] = 100001;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
		}
	}
	if (dp[k] >= 100001)
	{
		cout << "-1\n";
	}
	else
	{
		cout << dp[k] << "\n";
	}

}