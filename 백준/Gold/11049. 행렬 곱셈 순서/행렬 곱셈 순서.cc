#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {

	int dp[500][500];
	vector<pair<int, int>> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		int r, c;
		cin >> r >> c;
		v.push_back({ r, c });
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j + i < N; j++)
		{
			dp[j][j + i] = INT_MAX;
			for (int k = j; k < j + i; k++)
			{
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i]
					+ v[j].first * v[k].second * v[j + i].second);
			}
		}
	}
	cout << dp[0][N - 1];

}