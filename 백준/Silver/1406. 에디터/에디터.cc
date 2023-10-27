#include <iostream>
#include <list>
using namespace std;

list<char> a;

int main() {

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		a.push_back(str[i]);
	}
	int n;
	cin >> n;
	list<char>::iterator iter;
	iter = a.end();
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if (c == 'L') {
			if (a.begin() != iter)
			{
				iter--;
			}
		}
		else if (c == 'D') {
			if (a.end() != iter)
			{
				iter++;
			}
		}
		else if (c == 'B') {
			if (a.begin() != iter)
			{
				iter--;
				iter = a.erase(iter);
			}
		}
		else if (c == 'P') {
			char w;
			cin >> w;
			a.insert(iter, w);
		}
	}
	for (iter = a.begin(); iter != a.end(); iter++)
	{
		cout << *iter;
	}
}