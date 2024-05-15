#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <regex>

#define mod 1000000007;
typedef long long int ll;

using namespace std;

int n, m;
int tree[1001];
int node[1001];
int lc[1001];
int rc[1001];

int bin[2001][2001];
vector<int> v;
vector<int> ansv;

void bino() {
	bin[0][0] = 1;
	for (int i = 1; i <= 2000; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				bin[i][j] = 1;
			}
			else
			{
				bin[i][j] = (bin[i - 1][j] + bin[i - 1][j - 1]) % mod;
			}
		}
	}
}
void solve(int start) {
	if (start != -1)
	{
		solve(lc[start]);
		v.push_back(node[start]);
		solve(rc[start]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bino();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> node[i];
		cin >> lc[i];
		cin >> rc[i];
	}
	v.push_back(0);
	solve(1);
	v.push_back(m + 1);
	for (int i = 0; i < n + 2; i++)
	{
		if (v[i] == -1)
		{
			int start = v[i - 1];
			int cnt = 0;
			while (v[i] == -1)
			{
				i++;
				cnt++;
			}
			int end = v[i];
			int up = end - start - 1;
			ansv.push_back(bin[up][cnt]);
		}
	}
	ll ans = 1;
	for (int i = 0; i < ansv.size(); i++)
	{
		ans = (ans * ansv[i]) % mod;
	}
	cout << ans;
}