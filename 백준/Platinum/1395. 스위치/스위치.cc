#include <bits/stdc++.h>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int n, m;
int tree[400001];
int lazy[400001];

void push(int node, int start, int end) {
	if (lazy[node] == 0)
	{
		return;
	}

	tree[node] = (end - start + 1) - tree[node];
	if (start != end)
	{
		lazy[2 * node] = (lazy[2 * node] + lazy[node]) % 2;
		lazy[2 * node + 1] = (lazy[2 * node + 1] + lazy[node]) % 2;
	}
	lazy[node] = 0;
}
void update(int node, int start, int end, int left, int right) {
	push(node, start, end);
	if (end < left || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		lazy[node] = (lazy[node] + 1) % 2;
		push(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, left, right);
	update(2 * node + 1, mid + 1, end, left, right);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int left, int right) {
	push(node, start, end);
	if (end < left || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}

	int mid = (start + end) / 2;
	int leftans = query(2 * node, start, mid, left, right);
	int rightans = query(2 * node + 1, mid + 1, end, left, right);
	return leftans + rightans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int o, s, t;
		cin >> o;
		if (o == 0)
		{
			cin >> s >> t;
			update(1, 1, n, s, t);
		}
		else
		{
			cin >> s >> t;
			cout << query(1, 1, n, s, t) << "\n";
		}
	}
}