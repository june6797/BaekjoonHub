#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[201];
int dp[201];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans = max(dp[i], ans);
	}
	cout << n - ans;
}