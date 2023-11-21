#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double ans = 0;
	string str;
	cin >> str;
	cout << setprecision(1) << fixed;
	if (str[0] == 'A')
	{
		ans = 4;
		if (str[1] == '+')
		{
			cout << ans + 0.3;
		}
		else if (str[1] == '0')
		{
			cout << ans;
		}
		else
		{
			cout << ans - 0.3;
		}
	}
	else if (str[0] == 'B')
	{
		ans = 3;
		if (str[1] == '+')
		{
			cout << ans + 0.3;
		}
		else if (str[1] == '0')
		{
			cout << ans;
		}
		else
		{
			cout << ans - 0.3;
		}
	}
	else if (str[0] == 'C')
	{
		ans = 2;
		if (str[1] == '+')
		{
			cout << ans + 0.3;
		}
		else if (str[1] == '0')
		{
			cout << ans;
		}
		else
		{
			cout << ans - 0.3;
		}
	}
	else if (str[0] == 'D')
	{
		ans = 1;
		if (str[1] == '+')
		{
			cout << ans + 0.3;
		}
		else if (str[1] == '0')
		{
			cout << ans;
		}
		else
		{
			cout << ans - 0.3;
		}
	}
	else
	{
		cout << ans;
	}
}