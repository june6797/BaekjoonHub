#include <bits/stdc++.h>
#define mod 1000000009
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

ll dp[1001][1001][11];
int n, m, k;
vector<int> a;
vector<int> b;
ll solve(int s, int e, int len) {
	if (k == len)
	{
		return 1;
	}
	if (s == n || e == m)
	{
		return 0;
	}
	ll& ret = dp[s][e][len];
	if (ret != -1)
	{
		return ret;
	}
	ret = (solve(s + 1, e, len) + solve(s, e + 1, len) - solve(s + 1, e + 1, len) + mod) % mod;
	
	if (a[s] > b[e])
	{
		ret = (ret + solve(s + 1, e + 1, len + 1)) % mod;
	}
	
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		b.push_back(num);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	cout << solve(0, 0, 0);
}