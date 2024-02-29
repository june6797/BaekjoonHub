#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve(string s, string t) {
	if (s == t)
	{
		cout << 1;
		exit(0);
	}
	if (s.size() >= t.size())
	{
		return;
	}
	if (t[t.size() - 1] == 'A')
	{
		string temp = t;
		temp.erase(temp.size() - 1);
		solve(s, temp);
	}
	if (t[0] == 'B')
	{
		string temp = t;
		temp.erase(temp.begin());
		reverse(temp.begin(), temp.end());
		solve(s, temp);
	}
}
int main() {
	string s, t;
	cin >> s >> t;
	solve(s, t);
	cout << 0;
}