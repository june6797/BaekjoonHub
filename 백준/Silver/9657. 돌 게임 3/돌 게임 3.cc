#include <iostream>
using namespace std;

int dp[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i < 1001; i++)
	{
		if (dp[i - 1] == 2 || dp[i - 3] == 2 || dp[i - 4] == 2)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = 2;
		}
	}
	if (dp[N] == 1)
	{
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}
}