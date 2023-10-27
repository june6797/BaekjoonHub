#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int ans = 0;
	int minus = 0;
	string s = "";
	for (int i = 0; i <= str.length(); i++)
	{
		if (i == str.length())
		{
			if (minus == 0)
			{
				ans = ans + stoi(s);
				s = "";
			}
			else
			{
				ans = ans - stoi(s);
				s = "";
			}
		}
		else if (str.at(i) == '-')
		{
			if (minus == 0)
			{
				minus = 1;
				ans = ans + stoi(s);
				s = "";
			}
			else
			{
				ans = ans - stoi(s);
				s = "";
			}

		}
		else if (str.at(i) == '+')
		{
			if (minus == 0)
			{
				ans = ans + stoi(s);
				s = "";
			}
			else
			{
				ans = ans - stoi(s);
				s = "";
			}
		}

		else if (isdigit(str.at(i)))
		{
			s = s + str.at(i);
		}

	}
	cout << ans;
}