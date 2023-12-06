#include <iostream>
#include <string>
#include <stack>
using namespace std;

int dp[1001][1001];
stack<char> s;
void findword(int s1, int s2, string str) {
	int temp = dp[s1][s2];
	if (temp == 0)
	{
		return;
	}
	int up = dp[s1 - 1][s2];
	int right = dp[s1][s2 - 1];
	if (temp == up)
	{
		findword(s1 - 1, s2, str);
	}
	else if (temp == right)
	{
		findword(s1, s2 - 1, str);
	}
	else
	{
		s.push(str[s1 - 1]);
		findword(s1 - 1, s2 - 1, str);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
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
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[str1.size()][str2.size()] << "\n";
	findword(str1.size(), str2.size(), str1);
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}