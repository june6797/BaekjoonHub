#include <iostream>
using namespace std;

int arr[501];
int dp[50001];
int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= 50000; i++)
	{
		dp[i] = 101;
	}
	dp[0] = 0;
	for (int i = 0; i < N; i++)
	{
		int k = arr[i];
		for (int j = 50000 - k; j >= 0; j--)
		{
			dp[j + k] = min(dp[j + k], dp[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= 50000; i++)
	{
		if (dp[i] <= K)
		{
			ans++;
		}
	}
	cout << ans << "\n";
	for (int i = 1; i <= 50000; i++)
	{
		if (dp[i] <= K)
		{
			cout << i << " ";
		}
	}
}