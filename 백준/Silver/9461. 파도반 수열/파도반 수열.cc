#include <iostream>

using namespace std;

long long int dp[101];

int main() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}
}