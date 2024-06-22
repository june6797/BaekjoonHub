#include <bits/stdc++.h>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int n;
int arr[1000001];
int tree[4000001];

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx) {
	if (idx < start || end < idx)
	{
		return;
	}
	if (start == end)
	{
		tree[node]++;
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx);
	update(2 * node + 1, mid + 1, end, idx);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr[num] = i;
	}
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		int temp = arr[num];
		ans += query(1, 0, 1000000, temp, 1000000);
		update(1, 0, 1000000, temp);
	}
	cout << ans;
}