#include <iostream>
using namespace std;

int dp[31];
int main() {
	int N;
	cin >> N;
	dp[2] = 3;
	for (int i = 4; i <= N; i++)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j > 0; j = j - 2)
		{
			dp[i] += dp[j] * 2;
		}
		if (i % 2 == 0)
		{
			dp[i] += 2;
		}
	}
	cout << dp[N];
}