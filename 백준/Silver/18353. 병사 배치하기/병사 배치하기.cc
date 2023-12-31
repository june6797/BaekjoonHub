#include <iostream>
using namespace std;

int a[2001];
int dp[2001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	a[0] = 10000001;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] < a[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(dp[i], ans);
	}
	cout << N - ans;

}