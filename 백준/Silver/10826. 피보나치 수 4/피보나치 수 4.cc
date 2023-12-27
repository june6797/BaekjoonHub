#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string arr[10001];
string sum(string a, string b) {
	string ans = "";
	int carry = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (i >= b.size())
		{
			int num = a[i] - '0' + carry;
			if (num >= 10)
			{
				ans += to_string(num - 10);
				carry = 1;
			}
			else
			{
				ans += to_string(num);
				carry = 0;
			}
		}
		else
		{
			int num = a[i] - '0' + b[i] - '0' + carry;
			if (num >= 10)
			{
				ans += to_string(num - 10);
				carry = 1;
			}
			else
			{
				ans += to_string(num);
				carry = 0;
			}
		}
	}
	if (carry == 1)
	{
		ans += "1";
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	arr[0] = "0";
	arr[1] = "1";
	arr[2] = "1";
	for (int i = 3; i <= 10000; i++)
	{
		arr[i] = sum(arr[i - 1], arr[i - 2]);
	}
	int n;
	cin >> n;
	reverse(arr[n].begin(), arr[n].end());
	cout << arr[n];
}