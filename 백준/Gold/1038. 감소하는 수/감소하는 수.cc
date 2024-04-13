#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <string>
typedef long long int ll;
using namespace std;

int N;
vector<ll> v;

void solve(ll num) {
	v.push_back(num);
	int last = num % 10;
	for (int i = 0; i < last; i++)
	{
		solve(10 * num + i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < 10; i++)
	{
		solve(i);
	}
	sort(v.begin(), v.end());
	if (v.size() <= N)
	{
		cout << -1;
	}
	else
	{
		cout << v[N];
	}
}