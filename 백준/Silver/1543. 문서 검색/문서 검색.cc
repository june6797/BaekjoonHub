#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<char> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str, f;
	getline(cin, str);
	getline(cin, f);
	int ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		s.push_back(str[i]);
		if (str[i] == f[f.size() - 1] && s.size() >= f.size())
		{
			bool flag = false;
			for (int j = 0; j < f.size(); j++)
			{
				if (s[s.size() - f.size() + j] != f[j])
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{

			}
			else
			{
				s.clear();
				ans++;
			}
		}
	}
	cout << ans;
}