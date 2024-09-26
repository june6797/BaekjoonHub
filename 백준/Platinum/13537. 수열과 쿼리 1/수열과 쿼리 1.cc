#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m;
int arr[100001];
vector<int> tree[400001];

void update(int node, int start, int end, int target, int val) {
	if (target < start || target > end)
	{
		return;
	}
	tree[node].push_back(val);
	int mid = (start + end) / 2;
	if (start == end)
	{
		return;
	}
	update(2 * node, start, mid, target, val);
	update(2 * node + 1, mid + 1, end, target, val);
}

int query(int node, int start, int end, int left, int right, int k) {
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	}
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right, k) +
		query(2 * node + 1, mid + 1, end, left, right, k);
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
	for (int l = 0; l < m; l++)
	{
		int i, j, k;
		cin >> i >> j >> k;
		cout << query(1, 1, n, i, j, k) << "\n";
	}
}