#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

ll mul(ll a, ll b) {
	ll ret = 1;
	while (b)
	{
		if (b % 2 == 1)
		{
			ret = ret * a % mod;
		}
		b = b / 2;
		a = a * a % mod;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll left = i;
		ll right = n - i - 1;
		ll leftmul = mul(2, left) % mod;
		ll rightmul = mul(2, right) % mod;
		ans = (ans + ((leftmul - rightmul) * (v[i] % mod) % mod + mod)) % mod;
	}
	cout << ans;
}