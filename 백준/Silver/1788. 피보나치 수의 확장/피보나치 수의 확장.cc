#include <iostream>
using namespace std;

int dp[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
	}

	if (n > 0)
	{
		cout << "1\n" << dp[n];
	}
	else if (n < 0)
	{
		if (n % 2 == 0)
		{
			cout << "-1\n" << dp[-n];
		}
		else
		{
			cout << "1\n" << dp[-n];
		}
	}
	else
	{
		cout << "0\n0";
	}
}