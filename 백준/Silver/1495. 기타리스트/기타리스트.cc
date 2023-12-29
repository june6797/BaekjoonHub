#include <iostream>
using namespace std;

int v[51];
int dp[51][1001];
int main() {
	int N, S, M;
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}
	dp[0][S] = 1;
	for (int i = 1; i <= N; i++)
	{
		int vol = v[i];
		for (int j = 0; j <= 1000; j++)
		{
			if (j + vol <= M)
			{
				if (dp[i - 1][j] > 0)
				{
					dp[i][j + vol] = 1;
				}
			}
			if (j - vol >= 0)
			{
				if (dp[i - 1][j] > 0)
				{
					dp[i][j - vol] = 1;
				}
			}
		}
	}
	int ans = -1;
	
	for (int i = 0; i <= 1000; i++)
	{
		if (dp[N][i] > 0)
		{
			ans = i;
		}
	}
	cout << ans;
}