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

int n;
ll x;
ll arr[51];
ll p[51];
ll solve(int n, ll x) {
	if (n == 0)
	{
		return x;
	}
	if (x == 1)
	{
		return 0;
	}
	else if (x <= (1 + arr[n - 1])) {
		return solve(n - 1, x - 1);
	}
	else if (x == 2 + arr[n - 1]) {
		return p[n - 1] + 1;
	}
	else if (x <= 2 + 2 * arr[n - 1])
	{
		return p[n - 1] + 1 + solve(n - 1, x - arr[n - 1] - 2);
	}
	else
	{
		return 2 * p[n - 1] + 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> x;
	arr[0] = 1;
	p[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		arr[i] = 3 + 2 * arr[i - 1];
		p[i] = 2 * p[i - 1] + 1;
	}
	cout << solve(n, x);
}