#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <regex>

#define mod 1000000007;
typedef long long int ll;

using namespace std;

ll w, h, k;
int n, m;
vector<ll> a;
vector<ll> b;

ll ans = 0;
void solve(int idx) {
	int start = 0;
	int end = m;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (b[mid] * a[idx] > k)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	ans += start;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> w >> h >> k;
	cin >> n;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		ll temp;
		cin >> temp;
		a.push_back(temp - num);
		num = temp;
	}
	a.push_back(h - num);
	num = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		ll temp;
		cin >> temp;
		b.push_back(temp - num);
		num = temp;
	}
	b.push_back(w - num);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < n + 1; i++)
	{
		solve(i);
	}
	cout << ans;
}