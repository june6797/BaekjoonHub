#include <iostream>
using namespace std;
int dp[31];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int D, K;
	cin >> D >> K;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < 31; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int a = dp[D - 2];
	int b = dp[D - 1];
	for (int i = 1; i <= K; i++)
	{
		int first = a * i;
		if ((K - first) % b == 0)
		{
			cout << i << "\n" << (K - first) / b;
			break;
		}
	}
}