#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <queue>
typedef long long int ll;
using namespace std;

ll m = 1000000007;

ll solve(ll r, ll n) {
	if (n == 1)
	{
		return r % m;
	}
	else
	{
		ll x = solve(r, n / 2) % m;
		if (n % 2 == 0)
		{
			return ((x % m) * (x % m)) % m;
		}
		else
		{
			return (((x % m) * (x % m) % m) * (r % m)) % m;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a, b;
	cin >> a >> b;
	if (a == 1)
	{
		cout << b % m;
	}
	else
	{
		ll k = ((solve(a, b) % m) - 1 + m) % m;
		ll l = (solve(a - 1, m - 2)) % m;
		cout << (k * l) % m;
	}
}
