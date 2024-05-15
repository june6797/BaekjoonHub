#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <regex>

#define mod 1000000007;
typedef long long int ll;

using namespace std;

int dp[3001][2];

int checkup(char a) {
	if (a >= 'A' && a <= 'Z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkdown(char a) {
	if (a >= 'A' && a <= 'Z')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> str;
	if (checkup(str[0]))
	{
		dp[0][0] = 2;
		dp[0][1] = 2;
	}
	else
	{
		dp[0][0] = 1;
		dp[0][1] = 2;
	}
	for (int i = 1; i < str.size(); i++)
	{
		dp[i][0] = min(dp[i - 1][0] + checkup(str[i]) + 1,
			dp[i - 1][1] + 2);

		dp[i][1] = min(dp[i - 1][1] + checkdown(str[i]) + 1,
			dp[i - 1][0] + 2);
	}
	cout << min(dp[str.size() - 1][0], dp[str.size() - 1][1]);
}