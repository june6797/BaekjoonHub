#include <iostream>
using namespace std;

bool IsP[2501][2501];
int dp[2501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 1; i <= len; i++)
	{
		dp[i] = 987654321;
		for (int j = 1; j + i - 1 <= len; j++)
		{
			if (i == 1)
			{
				IsP[j][j] = true;
			}
			else if (i == 2)
			{
				if (str[j] == str[j - 1])
				{
					IsP[j][j + 1] = true;
				}
			}
			else
			{
				if (str[j - 1] == str[j + i - 2] && IsP[j + 1][j + i - 2] == true)
				{
					IsP[j][j + i - 1] = true;
				}
			}
		}
	}

	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (IsP[j][i] == true)
			{
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}
	cout << dp[len];
}