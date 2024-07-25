#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int t, n, d;
ll mat[101][21][21];
ll ans[21][21];
ll cycle[21][21];
void solve(int idx) {
	ll temp[21][21] = { 0, };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				temp[i][j] += (ans[i][k] * mat[idx][k][j]) % mod;
				temp[i][j] %= mod;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans[i][j] = temp[i][j];
		}
	}
}

void solvemul(int idx) {
	ll temp[21][21] = { 0, };
	if (idx == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					temp[i][j] += (ans[i][k] * cycle[k][j]) % mod;
					temp[i][j] %= mod;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				ans[i][j] = temp[i][j];
			}
		}
	}
	else if (idx == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					temp[i][j] += (cycle[i][k] * cycle[k][j]) % mod;
					temp[i][j] %= mod;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cycle[i][j] = temp[i][j];
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t >> n >> d;
	for (int i = 1; i <= t; i++)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			mat[i][a][b] = c;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				ans[i][j] = 1;
			}
		}
	}
	int multime = d / t;
	int modtime = d % t;
	if (multime >= 1)
	{
		for (int i = 0; i < t; i++)
		{
			int temp = i % t + 1;
			solve(temp);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cycle[i][j] = ans[i][j];
			}
		}
		multime--;
		while (multime)
		{
			if (multime & 1)
			{
				solvemul(1);
			}
			multime /= 2;
			solvemul(2);
		}
	}

	for (int i = 0; i < modtime; i++)
	{
		int temp = i % t + 1;
		solve(temp);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}