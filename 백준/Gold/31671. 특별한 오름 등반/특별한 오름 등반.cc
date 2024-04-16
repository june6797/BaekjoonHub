#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <string>
#include <regex>
typedef long long int ll;
using namespace std;

int n, m;
int teach[1001][2001];
int cache[1001][2001];
bool flag = false;
int ans = -1;
int solve(int x, int y, int cnt) {
	if (x == 2 * n && y == 0)
	{
		ans = max(ans, cnt);
		return y;
	}
	int& ret = cache[y][x];
	if (ret != -1)
	{
		return ret;
	}
	ret = -1;
	if (x + y + 2 <= 2 * n && teach[y + 1][x + 1] == 0)
	{
		ret = max(solve(x + 1, y + 1, max(cnt, y + 1)), 0);
	}
	if (y - 1 >= 0 && teach[y - 1][x + 1] == 0)
	{
		ret = max(solve(x + 1, y - 1, cnt), 0);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		teach[b][a] = 1;
	}
	solve(0, 0, 0);
	cout << ans;
	/*
	if (flag)
	{
		cout << ans;
	}
	else
	{
		cout << "-1\n";
	}*/
}