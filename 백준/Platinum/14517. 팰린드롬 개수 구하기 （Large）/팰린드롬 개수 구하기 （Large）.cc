#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int dp[1001][1001];
string str;
int solve(int s, int e) {
	if (s > e)
	{
		return 0;
	}
	else if (s == e) {
		return 1;
	}
	int& ret = dp[s][e];
	if (ret != -1)
	{
		return ret;
	}
	ret = (solve(s + 1, e) + solve(s, e - 1) - solve(s + 1, e - 1) + 10007) % 10007;
	if (str[s] == str[e])
	{
		ret = (ret + solve(s + 1, e - 1) + 1) % 10007;
	}
	
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> str;
	cout << solve(0, str.size() - 1);
}