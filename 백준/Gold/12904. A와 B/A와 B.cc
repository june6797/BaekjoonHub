#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	while (s.size() != t.size())
	{
		if (t.back() == 'B')
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		else
		{

			t.pop_back();
		}
		
	}
	if (s == t)
	{
		cout << "1\n";
	}
	else
	{
		cout << "0\n";
	}
}