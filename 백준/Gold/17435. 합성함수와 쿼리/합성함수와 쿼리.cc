#include <bits/stdc++.h>
#define mod 1000000009
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int arr[500001];
int parent[20][500001];
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> parent[0][i];
	}
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int n, x;
		cin >> n >> x;
		for (int j = 19; j >= 0; j--)
		{
			if (n >= (1 << j))
			{
				n -= (1 << j);
				x = parent[j][x];
			}
		}
		cout << x << "\n";
	}

}