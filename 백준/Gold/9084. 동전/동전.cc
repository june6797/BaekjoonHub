#include <iostream>
using namespace std;

int coin[21];
int dp[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> coin[i];
		}
		int M;
		cin >> M;
		dp[0] = 1;
		for (int i = 1; i <= N; i++)
		{
			for (int j = coin[i]; j <= M; j++)
			{
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[M] << "\n";
		for (int i = 1; i <= M; i++)
		{
			dp[i] = 0;
		}
	}

}