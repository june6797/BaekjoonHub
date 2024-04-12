#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int n, k;
ll arr[2001][2001];
ll dp[2001];
void bino() {
	for (int i = 0; i < 2001; i++)
	{
		arr[i][0] = arr[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % mod;
		}
	}
}

void solve() {
	dp[1] = 1;
	for (int i = 2; i < 2001; i++)
	{
		dp[i] = (dp[i - 1] * 2) % mod;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	bino();
	solve();
	cout << (arr[n][k] * dp[k]) % mod;
}