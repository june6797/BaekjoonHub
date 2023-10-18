#include <iostream>
#include <stack>

using namespace std;

stack<char> s;
int main() {
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < str.length(); i++)
	{
		char a = str[i];
		if (a == '(')
		{
			s.push(a);
		}
		else
		{
			s.pop();
			if (str[i - 1] == '(')
			{
				ans += s.size();
			}
			else
			{
				ans += 1;
			}
		}

	}
	cout << ans;
}