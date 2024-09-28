#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m;
ll arr[500001];
ll tree[2000001];
ll lazy[2000001];

void init(int node, int start, int end) {
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	init(2 * node, start, mid);
	init(2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] ^ tree[2 * node + 1];
	return;
}

void propagation(int node, int start, int end) {
	if (lazy[node] != 0)
	{
		if ((end - start + 1) % 2 == 1)
		{
			tree[node] ^= lazy[node];
		}
		if (start != end)
		{
			lazy[2 * node] ^= lazy[node];
			lazy[2 * node + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}


void update(int node, int start, int end, int left, int right, int diff) {
	propagation(node, start, end);

	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		lazy[node] ^= diff;
		propagation(node, start, end);
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, left, right, diff);
	update(2 * node + 1, mid + 1, end, left, right, diff);
	tree[node] = tree[2 * node] ^ tree[2 * node + 1];
}

int query(int node, int start, int end, int left, int right) {
	propagation(node, start, end);

	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right) ^
		query(2 * node + 1, mid + 1, end, left, right);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	init(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num, a, b, c;
		cin >> num;
		if (num == 1)
		{
			cin >> a >> b >> c;
			update(1, 1, n, a + 1, b + 1, c);
		}
		else
		{
			cin >> a >> b;
			cout << query(1, 1, n, a + 1, b + 1) << "\n";
		}
	}
}