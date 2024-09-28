#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m;
int arr[100001];
int tree[400001];

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
void update(int node, int start, int end, int target, int diff) {
	if (start > target || end < target)
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

ll query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right) +
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
		if (arr[i] % 2 == 0)
		{
			arr[i] = 1;
		}
		else
		{
			arr[i] = 0;
		}
	}
	init(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			if (c % 2 == 0)
			{
				c = 1;
			}
			else
			{
				c = 0;
			}
			int diff = c - arr[b];
			arr[b] = c;
			update(1, 1, n, b, diff);
		}
		else if (a == 2)
		{
			cout << query(1, 1, n, b, c) << "\n";
		}
		else
		{
			cout << c - b + 1 - query(1, 1, n, b, c) << "\n";
		}
	}
	
	
}