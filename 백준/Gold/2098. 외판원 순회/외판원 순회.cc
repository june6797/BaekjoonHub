#include <iostream>
using namespace std;

int INF = 987654321;
int W[16][16];
int dp[16][(1 << 16)];
int DFS(int c, int v, int N) {
	if (v == (1 << N) - 1)
	{
		if (W[c][0] == 0)
		{
			return INF;
		}
		return W[c][0];
	}
	if (dp[c][v] != 0)
	{
		return dp[c][v];
	}
	int m = INF;
	for (int i = 0; i < N; i++)
	{
		if ((v & (1 << i)) == 0 && W[c][i] != 0)
		{
			m = min(m, DFS(i, v | 1 << i, N) + W[c][i]);
		}
	}
	dp[c][v] = m;
	return dp[c][v];
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}
	cout << DFS(0, 1, N);
}