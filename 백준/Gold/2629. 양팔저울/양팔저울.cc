#include <iostream>
using namespace std;

int w[31];
int dp[31][40001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> w[i];
		dp[i][0] = 1;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 40001; j++)
		{
			if (dp[i - 1][j] > 0)
			{
				int p = j + w[i];
				int m = abs(j - w[i]);
				if (p <= 40000)
				{
					dp[i][p] = 1;
				}
				if (m >= 0)
				{
					dp[i][m] = 1;
				}
				dp[i][j] = 1;
			}
		}
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int num;
		cin >> num;
		if (dp[N][num] == 1)
		{
			cout << "Y";
		}
		else
		{
			cout << "N";
		}
		cout << " ";
	}
}