#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m, k;
ll arr[400001];
ll tree[400001];

void update(int node, int start, int end, int target, int diff) {
	if (target > end || target < start)
	{
		return;
	}
	if (start == end)
	{
		tree[node] += diff;
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, target, diff);
	update(2 * node + 1, mid + 1, end, target, diff);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(int node, int start, int end, int val) {
	if (start == end)
	{
		return start;
	}
	int mid = (start + end) / 2;
	if (tree[2 * node] >= val)
	{
		return query(2 * node, start, mid, val);
	}
	else
	{
		return query(2 * node + 1, mid + 1, end, val - tree[2 * node]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i];
	}
	for (int i = 1; i < k; i++)
	{
		update(1, 0, 70000, arr[i], 1);
	}
	ll ans = 0;
	for (int i = k; i <= n; i++)
	{
		update(1, 0, 70000, arr[i], 1);
		ans += query(1, 0, 70000, (k + 1) / 2);
		update(1, 0, 70000, arr[i - k + 1], -1);
	}
	cout << ans;
}