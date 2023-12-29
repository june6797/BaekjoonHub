#include <iostream>
using namespace std;
long long int dp[68];
int main() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 67; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
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