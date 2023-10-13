#include <iostream>
#include <stack>

using namespace std;

int main() {

	int T;
	string str, f;

	cin >> str >> f;
	int fidx = 0;
	int flag = 0;
	stack <int> s;
	stack <int> v;

	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) != f.at(fidx))
		{
			if (str.at(i) != f.at(0))
			{
				flag = 1;
				while (!s.empty())
				{
					v.push(s.top());
					s.pop();
				}
				while (!v.empty())
				{
					cout << f.at(v.top());
					v.pop();
				}
				cout << str.at(i);
				fidx = 0;
			}
			else
			{
				fidx = 0;
				s.push(fidx);
				fidx = 1;
			}
		}
		else
		{
			s.push(fidx);
			fidx++;
			if (fidx == f.length())
			{
				for (int i = 0; i < f.length(); i++)
				{
					s.pop();
				}

				if (s.empty()) {
					fidx = 0;
				}
				else
				{
					fidx = s.top() + 1;
				}
			}

		}
	}

	if (!s.empty())
	{
		flag = 1;
		while (!s.empty())
		{
			v.push(s.top());
			s.pop();
		}
		while (!v.empty())
		{
			cout << f.at(v.top());
			v.pop();
		}
	}
	else
	{
		if (flag == 0) {
			cout << "FRULA";
		}
	}

	cout << "\n";


}