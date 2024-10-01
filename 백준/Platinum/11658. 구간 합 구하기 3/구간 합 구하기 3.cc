#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1234567890
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, m;

int arr[1025][1025];
int tree[1025][1025];

//다차원 팬윅트리임
int query(int x, int y) {
	int ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
	{
		for (int j = y; j > 0; j -= (j & -j))
		{
			ret += tree[i][j];
		}
	}
	return ret;
}

void update(int x, int y, int num) {
	for (int i = x; i <= n; i += (i & -i))
	{
		for (int j = y; j <= n; j += (j & -j))
		{
			tree[i][j] += num;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//다차원 세그먼트 공부
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			update(i, j, arr[i][j]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		int w, x1, y1, x2, y2;
		cin >> w;
		if (w == 0)
		{
			cin >> x1 >> y1 >> x2;
			update(x1, y1, x2 - arr[x1][y1]);
			arr[x1][y1] = x2;
		}
		else
		{
			cin >> x1 >> y1 >> x2 >> y2;
			cout << query(x2, y2) - query(x2, y1 - 1)
				- query(x1 - 1, y2) + query(x1 - 1, y1 - 1) << "\n";
		}
	}
}