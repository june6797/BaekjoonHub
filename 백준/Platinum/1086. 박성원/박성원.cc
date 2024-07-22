#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

int n, k;
int ten[51];
ll dp[1 << 15][101];
string str[16];
int strmod[16];
int len[16];

int solve_mod(string str) {
	int ret = 0;
	for (int i = 0; i < str.size(); i++)
	{
		ret *= 10;
		ret += str[i] - '0';
		ret %= k;
	}
	return ret;
}

ll gcd(ll a, ll b) {
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		len[i] = str[i].size();
	}
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		strmod[i] = solve_mod(str[i]);
	}
	
	ten[0] = 1;
	for (int i = 1; i < 51; i++)
	{
		ten[i] = (10 * ten[i - 1]) % k;
	}
	dp[0][0] = 1;
	for (int idx = 0; idx < (1 << n); idx++)
	{
		for (int i = 0; i < n; i++)
		{
			if ((idx & (1 << i)) == 0)
			{
				int next = (idx | (1 << i));
				for (int j = 0; j < k; j++)
				{
					int nextmod = ((j * ten[len[i]]) % k + strmod[i]) % k;
					dp[next][nextmod] += dp[idx][j];
				}
			}
		}
	}
	ll up = 1, down = 1;
	for (int i = 1; i <= n; i++)
	{
		down *= i;
	}
	up = dp[(1 << n) - 1][0];
	ll temp = gcd(up, down);
	cout << up / temp << "/" << down / temp;
}