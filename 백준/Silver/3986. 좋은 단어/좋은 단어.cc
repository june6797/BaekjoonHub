#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

stack<char> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (s.empty())
			{
				s.push(str[j]);
			}
			else
			{
				if (s.top() == str[j]) {
					s.pop();
				}
				else
				{
					s.push(str[j]);
				}

			}

		}
		if (s.empty())
		{
			ans++;
		}
		else
		{
			while (!s.empty())
			{
				s.pop();
			}
		}
	}
	cout << ans;
}