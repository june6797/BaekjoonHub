#include <iostream>
#include <bitset>
using namespace std;

int score[301];
int dp[301];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int s;
		cin >> s;
		score[i] = s;
	}
	dp[1] = score[1];
	dp[2] = score[1] + score[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
	}
	cout << dp[n];
}