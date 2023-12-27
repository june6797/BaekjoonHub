#include <iostream>
using namespace std;
long long int dp[101][21];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	int num;
	cin >> num;
	dp[1][num] = 1;
	for (int i = 2; i < N; i++)
	{
		cin >> num;

		for (int j = 0; j <= 20 - num; j++)
		{
			dp[i][j] += dp[i - 1][j + num];
		}

		for (int j = 20; j >= num; j--)
		{
			dp[i][j] += dp[i - 1][j - num];
		}

	}
	cin >> num;
	cout << dp[N - 1][num];
}