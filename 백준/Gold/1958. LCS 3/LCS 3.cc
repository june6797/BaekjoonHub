#include <iostream>
using namespace std;

int dp[101][101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;
	int x = str1.size();
	int y = str2.size();
	int z = str3.size();
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			for (int k = 1; k <= z; k++)
			{
				if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
					dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
				}
			}
		}
	}
	cout << dp[str1.size()][str2.size()][str3.size()];
}