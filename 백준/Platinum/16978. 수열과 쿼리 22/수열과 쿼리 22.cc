#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1234567890
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m;


ll tree[4000001];
ll ans[1000001];


struct qq {
	int k, s, e, idx;
};

bool cmp(qq a, qq b) {
	return a.k < b.k;
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

	ll lm = query(2 * node, start, mid, left, right);
	ll rm = query(2 * node + 1, mid + 1, end, left, right);
	return lm + rm;
}

void update(int node, int start, int end, int idx, int value) {
	if (idx < start || idx > end)
	{
		return;
	}
	tree[node] += value;
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

	//오프라인쿼리 공부

	vector<pii> fq;
	vector<qq> sq;
	int cnt = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int x, y;
			cin >> x >> y;
			fq.push_back({ x, y });
		}
		else
		{
			int x, y, z;
			cin >> x >> y >> z;
			sq.push_back({ x, y, z , cnt++ });
		}
	}

	sort(sq.begin(), sq.end(), cmp);
	int kk = 0;
	for (int i = 0; i < fq.size(); i++)
	{
		while (sq[kk].k == i)
		{
			qq temp = sq[kk];
			ans[temp.idx] = query(1, 1, n, temp.s, temp.e);
			kk++;
		}
		pii temp = fq[i];
		temp.second = temp.second - query(1, 1, n, temp.first, temp.first);
		update(1, 1, n, temp.first, temp.second);
	}
	for (int i = kk; i < sq.size(); i++)
	{
		ans[sq[i].idx] = query(1, 1, n, sq[i].s, sq[i].e);
	}
	for (int i = 0; i < sq.size(); i++)
	{
		cout << ans[i] << "\n";
	}
}