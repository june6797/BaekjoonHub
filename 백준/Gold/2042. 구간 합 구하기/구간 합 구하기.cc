#include <bits/stdc++.h>
#define mod 1000000007;
#define INF 1234567890;
typedef long long ll;
using namespace std;

int n, m, k;
ll arr[1000001];
ll tree[4000001];

void init(int node, int start, int end) {
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	init(2 * node, start, mid);
	init(2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
	return;
}

void update(int node, int start, int end, int target, ll diff) {
	if (target < start || target > end)
	{
		return;
	}
	tree[node] += diff;
	if (start == end)
	{
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, target, diff);
	update(2 * node + 1, mid + 1, end, target, diff);
}
ll treesum(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return treesum(2 * node, start, mid, left, right) + treesum(2 * node + 1, mid + 1, end, left, right);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	init(1, 1, n);
	for (int i = 0; i < m + k; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			ll diff = c - arr[b];
			arr[b] = c;
			update(1, 1, n, b, diff);
		}
		else
		{
			cout << treesum(1, 1, n, b, c) << "\n";
		}
	}
}
