#include <bits/stdc++.h>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int n;
int arr[1000000];
int tree[4000000];

int query(int node, int start, int end, int k) {
	if (start == end)
	{
		return end;
	}
	int mid = (start + end) / 2;
	if (tree[2 * node] >= k)
	{
		return query(2 * node, start, mid, k);
	}
	else
	{
		return query(2 * node + 1, mid + 1, end, k - tree[2 * node]);
	}
}
void update(int node, int start, int end, int idx, ll diff) {
	if (idx < start || idx > end)
	{
		return;
	}
	if (start == end)
	{
		tree[node] = diff;
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, diff);
	update(2 * node + 1, mid + 1, end, idx, diff);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b;
			int temp = query(1, 0, 1000000, b);
			cout << temp << "\n";
			update(1, 0, 1000000, temp, arr[temp] - 1);
			arr[temp] -= 1;
		}
		else
		{
			cin >> b >> c;
			update(1, 0, 1000000, b, arr[b] + c);
			arr[b] += c;
		}
	}
}