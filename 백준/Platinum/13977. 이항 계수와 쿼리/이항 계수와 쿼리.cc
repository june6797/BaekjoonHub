#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

ll fac[4000001];
ll solve(ll a, ll b) {
	ll ret = 1;
	while (b)
	{
		if (b & 1)
		{
			ret = ret * a % mod;
		}
		b /= 2;
		a = a * a % mod;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> m;
	fac[0] = 1;
	for (int i = 1; i < 4000001; i++)
	{
		fac[i] = (i * fac[i - 1]) % mod;
	}
	for (int i = 0; i < m; i++)
	{
		int n, k;
		cin >> n >> k;
		ll up = fac[n];
		ll down = (fac[k] * fac[n - k]) % mod;
		ll temp = (solve(down, mod - 2)) % mod;
		cout << (up * temp) % mod << "\n";
	}
}