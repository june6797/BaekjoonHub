#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1234567890
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m;

int arr[100001];
vector<int> tree[400001];

int query(int node, int start, int end, int left, int right, int val) {
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
	}
	int mid = (start + end) / 2;
	int l = query(2 * node, start, mid, left, right, val);
	int r = query(2 * node + 1, mid + 1, end, left, right, val);
	return l + r;
}

void update(int node, int start, int end, int idx, int value) {
	if (idx < start || idx > end)
	{
		return;
	}
	tree[node].push_back(value);
	if (start == end)
	{
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, value);
	update(2 * node + 1, mid + 1, end, idx, value);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		update(1, 1, n, i, num);
	}
	for (int i = 1; i <= 4 * n; i++)
	{
		sort(tree[i].begin(), tree[i].end());
	}
	cin >> m;
	int last = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int x = a ^ last;
		int y = b ^ last;
		int z = c ^ last;
		last = query(1, 1, n, x, y, z);
		cout << last << "\n";
	}
}