#include <iostream>
#include <climits>
using namespace std;

int dp[100001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = INT_MAX;
	}
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[N];
}