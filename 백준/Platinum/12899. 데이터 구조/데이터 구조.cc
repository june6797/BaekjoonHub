#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1234567890
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m;

int tree[8000001];

int query(int node, int start, int end, int val) {

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

void update(int node, int start, int end, int idx, int value) {
	if (idx < start || idx > end)
	{
		return;
	}
	if (start == end)
	{
		tree[node] += value;
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, value);
	update(2 * node + 1, mid + 1, end, idx, value);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, x;
		cin >> t >> x;
		if (t == 1)
		{
			update(1, 1, 2000001, x, 1);
		}
		else if (t == 2)
		{
			int temp = query(1, 1, 2000001, x);
			cout << temp << "\n";
			update(1, 1, 2000001, temp, -1);
		}
	}
}