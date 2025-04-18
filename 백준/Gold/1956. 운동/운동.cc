#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
#include <cstdio>
using namespace std;

int arr[401][401];
int v, e, ans = 987654321;
void solve() {
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			for (int k = 1; k <= v; k++)
			{
				if (arr[i][k] + arr[k][j] < arr[i][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
		{
			arr[i][j] = 987654321;
			if (i == j)
			{
				arr[i][j] = 0;
			}
		}
	}
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}
	solve();
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i != j)
			{
				ans = min(ans, arr[i][j] + arr[j][i]);
			}
		}
	}
	if (ans == 987654321)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
}
