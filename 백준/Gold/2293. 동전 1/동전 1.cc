#include <iostream>

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
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k] << "\n";

}