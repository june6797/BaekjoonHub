#include <iostream>
using namespace std;

int dp[41];
int main() {
	int N, M;
	cin >> N >> M;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 40; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int ans = 1;
	int small = 0;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		if (num - small - 1 > 0)
		{
			ans *= dp[num - small - 1];
		}
		small = num;
	}
	if (N - small > 0)
	{
		ans *= dp[N - small];
	}
	cout << ans;
}