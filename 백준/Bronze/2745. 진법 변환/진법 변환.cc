#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int b;
	string str;
	cin >> str >> b;
	int ans = 0;
	int temp = 1;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		int t = 0;
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			t = str[i] - 'A' + 10;
		}
		else
		{
			t = str[i] - '0';
		}
		ans += (temp * t);
		temp *= b;
	}
	cout << ans;
}
