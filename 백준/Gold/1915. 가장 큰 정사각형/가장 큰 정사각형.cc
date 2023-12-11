#include <iostream>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = str[j - 1] - '0';
			dp[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dp[i][j] == 1)
			{
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
				dp[i][j] = min(dp[i][j], dp[i][j - 1]) + 1;
				if (ans < dp[i][j])
				{
					ans = dp[i][j];
				}
			}
		}
	}
	cout << ans * ans;
}