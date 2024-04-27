#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int arr[1001];
int visit[1001];
int ans;

void solve(int start) {
	if (visit[start] == 1)
	{
		ans++;
		return;
	}
	visit[start] = 1;
	solve(arr[start]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			arr[i] = a;
		}
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 0)
			{
				solve(i);
			}
		}
		cout << ans << "\n";
		for (int i = 1; i <= n; i++)
		{
			visit[i] = 0;
		}
	}
}