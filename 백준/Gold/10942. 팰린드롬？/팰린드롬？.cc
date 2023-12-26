#include <iostream>
using namespace std;

int arr[2001];
int dp[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i <= N - 1; i++)
	{
		for (int j = 1; i + j <= N; j++)
		{
			if (i == 0)
			{
				dp[j][i + j] = 1;
			}
			else if (i == 1)
			{
				if (arr[j] == arr[i + j])
				{
					dp[j][i + j] = 1;
				}
			}
			else
			{
				if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1] == 1)
				{
					dp[j][i + j] = 1;
				}
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
}