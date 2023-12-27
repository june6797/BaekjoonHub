#include <iostream>
using namespace std;

long long int dp[5001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	bool make = false;
	if (str[0] - '0' == 0)
	{
		make = true;
	}
	else
	{
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 1; i < str.size(); i++)
		{
			if (str[i] == '0')
			{
				if (str[i - 1] - '0' == 1 || str[i - 1] - '0' == 2)
				{
					dp[i + 1] = dp[i - 1] % 1000000;
				}
				else
				{
					make = true;
					break;
				}
			}
			else
			{
				int num = (str[i - 1] - '0') * 10 + (str[i] - '0');
				if (num < 27 && str[i - 1] - '0' != 0)
				{
					dp[i + 1] = (dp[i] + dp[i - 1]) % 1000000;
				}
				else
				{
					dp[i + 1] = dp[i] % 1000000;
				}

			}
		}
	}
	if (make)
	{
		cout << "0\n";
	}
	else
	{
		cout << dp[str.size()] % 1000000 << "\n";
	}

}