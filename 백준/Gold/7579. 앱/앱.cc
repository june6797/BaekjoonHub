#include <iostream>
#include <string>
#include <stack>
using namespace std;

int memory[101];
int cost[101];
int dp[101][10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, costsum = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> memory[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
		costsum += cost[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= costsum; j++)
		{
			if (j - cost[i] >= 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	for (int i = 0; i <= costsum; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i;
			break;
		}
	}
}