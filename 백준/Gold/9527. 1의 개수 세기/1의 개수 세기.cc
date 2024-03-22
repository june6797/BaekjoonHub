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

ll arr[55];

ll sum(ll x) {
	ll ans = x & 1;
	for (ll i = 54; i > 0; i--)
	{
		if (x & (1LL << i)) {
			ans += arr[i - 1] + (x - (1LL << i) + 1);
			x -= (1LL << i);
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll A, B;
	cin >> A >> B;
	arr[0] = 1;
	for (ll i = 1; i < 55; i++)
	{
		arr[i] = arr[i - 1] * 2 + pow(2, i);
	}
	cout << sum(B) - sum(A - 1);
}
