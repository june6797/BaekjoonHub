#include <bits/stdc++.h>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int n, m, k;
ll arr[1000001];
ll tree[4000001];
ll lazy[4000001];
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
}

void propagation(int node, int start, int end) {
	if (lazy[node] == 0)
	{
		return;
	}
	tree[node] += lazy[node] * (end - start + 1);
	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}


void update(int node, int start, int end, int left, int right, ll diff) {
	propagation(node, start, end);
	if (end < left || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		lazy[node] += diff;
		propagation(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, left, right, diff);
	update(2 * node + 1, mid + 1, end, left, right, diff);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(int node, int start, int end, int left, int right) {
	propagation(node, start, end);
	if (end < left || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	ll leftans = query(2 * node, start, mid, left, right);
	ll rightans = query(2 * node + 1, mid + 1, end, left, right);
	return leftans + rightans;
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
		ll a, b, c, d;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			update(1, 1, n, b, c, d);
		}
		else
		{
			cin >> b >> c;
			cout <<	query(1, 1, n, b, c) << "\n";
		}
	}
}