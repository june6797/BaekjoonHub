#include <iostream>
using namespace std;

int dp[4001][4001];
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int ans = 0;
	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				//이 문제는 최장공통 부분 문자열 문제
				// 최장공통 부분 수열 문제가 아님
				//dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}