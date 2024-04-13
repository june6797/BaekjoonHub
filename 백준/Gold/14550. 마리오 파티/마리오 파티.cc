#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <string>
typedef long long int ll;
using namespace std;

int n, s, t, ans = -987654321;
int arr[231];
int dp[201][201];
int solve(int idx, int cnt) {

	if (idx >= n + 1 && cnt <= t)
	{
		return 0;
	}
	else if (cnt > t)
	{
		return -123456789;
	}

	int& ret = dp[idx][cnt];
	if (ret != -1)
	{
		return ret;
	}
	ret = -123456789;
	for (int i = 1; i <= s; i++)
	{
		ret = max(ret, solve(idx + i, cnt + 1) + arr[idx]);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else
		{
			memset(arr, 0, sizeof(arr));
			memset(dp, -1, sizeof(dp));
			cin >> s >> t;
			for (int i = 1; i <= n; i++)
			{
				cin >> arr[i];
			}
			cout << solve(0, 0) << "\n";
		}
	}
}