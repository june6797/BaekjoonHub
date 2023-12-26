#include <iostream>
using namespace std;

int arr[501];
int sum[501];
int dp[501][501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int K;
		cin >> K;
		for (int i = 1; i <= K; i++)
		{
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		for (int i = 1; i <= K; i++)
		{
			dp[i][i] = 0;
		}
		for (int gap = 1; gap < K; gap++)
		{
			for (int i = 1; i + gap <= K; i++)
			{
				int m = 987654321;
				for (int j = i; j < i + gap; j++)
				{
					m = min(m, dp[i][j] + dp[j + 1][i + gap] + sum[i + gap] - sum[i - 1]);
				}
				dp[i][i + gap] = m;
			}
		}
		cout << dp[1][K] << "\n";
	}
}