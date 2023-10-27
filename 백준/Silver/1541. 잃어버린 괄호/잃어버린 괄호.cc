#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int num = 0;
	int ans = 0;
	bool flag = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			if (flag) {
				ans -= num;
			}
			else
			{
				ans += num;
			}
			num = 0;
			flag = true;
		}
		else if (str[i] == '+')
		{
			if (flag) {
				ans -= num;
			}
			else
			{
				ans += num;
			}
			num = 0;
		}
		else
		{
			num = 10 * num + str[i] - '0';
		}
	}
	if (flag) {
		ans -= num;
	}
	else
	{
		ans += num;
	}
	num = 0;
	cout << ans;
}