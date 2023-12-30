#include <iostream>
using namespace std;

long long int arr[1001][3];
long long int dp[1001][3];
long long int temp[3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	long long int ans = 987654321;
	for (int c = 0; c < 3; c++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == c)
			{
				dp[1][i] = arr[1][i];
			}
			else
			{
				dp[1][i] = 987654321;
			}
		}
		for (int i = 2; i <= N; i++)
		{
			dp[i][0] = min(dp[i - 1][1] + arr[i][0],
				dp[i - 1][2] + arr[i][0]);
			dp[i][1] = min(dp[i - 1][0] + arr[i][1],
				dp[i - 1][2] + arr[i][1]);
			dp[i][2] = min(dp[i - 1][0] + arr[i][2],
				dp[i - 1][1] + arr[i][2]);
		}
		for (int i = 0; i < 3; i++)
		{
			if (i != c)
			{
				ans = min(ans, dp[N][i]);
			}
		}
	}
	cout << ans;
}