#include <iostream>
#include <stack>
#include <deque>
#include <string>
using namespace std;

deque<char> l;
deque<char> r;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '<')
			{
				if (l.size() != 0)
				{
					char temp = l.back();
					r.push_front(temp);
					l.pop_back();
				}
			}
			else if (str[i] == '>')
			{
				if (r.size() != 0)
				{
					char temp = r.front();
					l.push_back(temp);
					r.pop_front();
				}
			}
			else if (str[i] == '-')
			{
				if (l.size() != 0)
				{
					l.pop_back();
				}
			}
			else
			{
				l.push_back(str[i]);
			}
		}
		while (!l.empty())
		{
			cout << l.front();
			l.pop_front();
		}
		while (!r.empty())
		{
			cout << r.front();
			r.pop_front();
		}
		cout << "\n";
	}


}