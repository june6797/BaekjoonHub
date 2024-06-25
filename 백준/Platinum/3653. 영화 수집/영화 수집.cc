#include <bits/stdc++.h>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int N, M;

int tree[800001];
int cd[200001];
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
	int leftans = query(2 * node, start, mid, left, right);
	int rightans = query(2 * node + 1, mid + 1, end, left, right);
	return leftans + rightans;
}

void update(int node, int start, int end, int idx, int diff) {
	if (idx > end || idx < start)
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
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
		{
			cd[i] = N - i + 1;
		}
		for (int i = 1; i <= N + M; i++)
		{
			if (i <= N)
			{
				update(1, 1, N + M, i, 1);
			}
			else
			{
				update(1, 1, N + M, i, 0);
			}
		}
		for (int i = 1; i <= M; i++)
		{
			int num;
			cin >> num;
			int target = cd[num];
			cout << query(1, 1, N + M, target + 1, N + i) << " ";
			update(1, 1, N + M, target, 0);
			update(1, 1, N + M, N + i, 1);
			cd[num] = N + i;
		}
		cout << "\n";
		memset(tree, 0, sizeof(tree));
		memset(cd, 0, sizeof(cd));
	}
}