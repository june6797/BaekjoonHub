#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m, k;
ll arr[200001];
ll dist_tree[200001];
ll cnt_tree[200001];

void update_cnt(int idx) {
	while (idx <= 200001)
	{
		cnt_tree[idx] += 1;
		idx = idx + (idx & -idx);
	}
}

void update_dist(int idx, int val) {
	while (idx <= 200001)
	{
		dist_tree[idx] += val;
		idx = idx + (idx & -idx);
	}
}
ll query_cnt(int idx) {
	ll res = 0;
	while (idx > 0)
	{
		res += cnt_tree[idx];
		idx = idx - (idx & -idx);
	}
	return res;
}

ll query_dist(int idx) {
	ll res = 0;
	while (idx > 0)
	{
		res += dist_tree[idx];
		idx = idx - (idx & -idx);
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	ll ans = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i]++;
	}
	update_cnt(arr[1]);
	update_dist(arr[1], arr[1]);
	for (int i = 2; i <= n; i++)
	{
		ll left_cnt = query_cnt(arr[i] - 1);
		ll right_cnt = query_cnt(200001) - query_cnt(arr[i]);
		ll left_dist = query_dist(arr[i] - 1);
		ll right_dist = query_dist(200001) - query_dist(arr[i]);

		ll left = arr[i] * left_cnt - left_dist;
		ll right = right_dist - arr[i] * right_cnt;
		left = left % mod;
		right = right % mod;
		ans = (ans * ((left + right) % mod)) % mod;

		update_cnt(arr[i]);
		update_dist(arr[i], arr[i]);
	}
	cout << ans % mod;
}