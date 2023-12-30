#include <iostream>
#include <vector>
using namespace std;
int dp[10001];
vector<pair<pair<int, int>, int>> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, D;
	cin >> N >> D;
	for (int i = 0; i < N; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		v.push_back({ {s, e}, c });
	}
	for (int i = 1; i <= D; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < N; j++)
		{
			if (v[j].first.second == i)
			{
				dp[i] = min(dp[v[j].first.first] + v[j].second, dp[i]);
			}
		}
	}
	cout << dp[D];
}