#include <iostream>
using namespace std;

long long int dp[82];
int main() {
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 81; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	int N;
	cin >> N;
	cout << 2 * (dp[N + 1] + dp[N]);
}