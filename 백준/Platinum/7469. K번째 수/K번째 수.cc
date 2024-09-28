#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m;
int arr[100001];
vector<int> tree[400001];

void update(int node, int start, int end, int target, int diff) {
	if (start > target || end < target)
	{
		return;
	}
	tree[node].push_back(diff);
	if (start == end)
	{
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, target, diff);
	update(2 * node + 1, mid + 1, end, target, diff);
}

ll query(int node, int start, int end, int left, int right, int mi) {
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return upper_bound(tree[node].begin(), tree[node].end(), mi) - tree[node].begin();
	}
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right, mi) +
		query(2 * node + 1, mid + 1, end, left, right, mi);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		update(1, 1, n, i, arr[i]);
	}
	for (int i = 0; i < 400001; i++)
	{
		sort(tree[i].begin(), tree[i].end());
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int lo = -1000000001;
		int hi = 1000000001;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (query(1, 1, n, a, b, mid) < c)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
		cout << lo << "\n";
	}


}