#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
		if (dp[i] == 0)
		{
			dp[i] = arr[i];
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (ans < dp[i])
		{
			ans = dp[i];
		}
	}
	cout << ans;
}
