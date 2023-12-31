#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<string> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;

	bool flag = false;
	int ans = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			s.push("(");
		}
		else if (str[i] == '[')
		{
			s.push("[");
		}
		else if (str[i] == ')')
		{
			int num = 0;
			while (!s.empty() && s.top() != "(")
			{
				string temp = s.top();
				if (temp == "[")
				{
					flag = true;
					break;
				}
				else
				{
					int temp = stoi(s.top());
					num += temp;
				}
				s.pop();
			}
			if (s.empty() || flag == true)
			{
				flag = true;
				break;
			}
			s.pop();
			if (num == 0)
			{
				s.push(to_string(2));
			}
			else
			{
				s.push(to_string(2 * num));
			}
		}
		else if (str[i] == ']')
		{
			int num = 0;
			while (!s.empty() && s.top() != "[")
			{
				string temp = s.top();
				if (temp == "(")
				{
					flag = true;
					break;
				}
				else
				{
					int temp = stoi(s.top());
					num += temp;
				}
				s.pop();
			}
			if (s.empty() || flag == true)
			{
				flag = true;
				break;
			}
			s.pop();
			if (num == 0)
			{
				s.push(to_string(3));
			}
			else
			{
				s.push(to_string(3 * num));
			}
		}
	}
	while (!s.empty())
	{
		if (s.top() == "(" || s.top() == "[")
		{
			flag = true;
			break;
		}
		ans += stoi(s.top());
		s.pop();
	}
	if (flag)
	{
		cout << 0;
	}
	else
	{
		cout << ans;
	}
}