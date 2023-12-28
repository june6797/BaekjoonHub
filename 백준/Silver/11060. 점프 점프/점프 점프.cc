#include <iostream>
using namespace std;

int dp[1001];
int maze[1001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> maze[i];
		dp[i] = 987654321;
	}
	dp[1] = 0;
	for (int i = 1; i <= N; i++)
	{
		int jump = maze[i];
		for (int j = 1; j <= jump; j++)
		{
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[N] != 987654321)
	{
		cout << dp[N];
	}
	else
	{
		cout << -1;
	}
}