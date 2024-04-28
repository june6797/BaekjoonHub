#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <regex>
typedef long long int ll;
using namespace std;
string str, ans = "";
void solve(int f, int s) {
	string a, b, c;
	a = "";
	b = "";
	c = "";
	for (int i = 0; i <= f; i++)
	{
		a += str[i];
	}
	for (int i = f + 1; i <= s; i++)
	{
		b += str[i];
	}
	for (int i = s + 1; i < str.size(); i++)
	{
		c += str[i];
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(c.begin(), c.end());
	string t = a + b + c;
	if (ans == "")
	{
		ans = t;
	}
	else
	{
		if (ans > t)
		{
			ans = t;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	for (int i = 0; i < str.size() - 2; i++)
	{
		for (int j = i + 1; j < str.size() - 1; j++)
		{
			solve(i, j);
		}
	}
	cout << ans;
}