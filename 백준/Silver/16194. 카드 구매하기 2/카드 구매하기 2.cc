#include <iostream>
using namespace std;

long long int dp[1001];
int arr[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i] = 987654321;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			dp[j] = min(dp[j], dp[j - i] + arr[i]);
		}
	}
	cout << dp[N];
}