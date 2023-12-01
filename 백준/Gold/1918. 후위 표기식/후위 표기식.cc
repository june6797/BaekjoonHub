#include <iostream>
#include <stack>
using namespace std;

stack<char> s;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			cout << str[i];
		}
		else if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			while (s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!s.empty() && (s.top() == '*' || s.top() == '/'))
			{
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!s.empty() && s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);

		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}