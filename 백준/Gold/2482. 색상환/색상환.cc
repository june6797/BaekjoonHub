#include <iostream>
using namespace std;

int dp[1001][1001];
int DFS(int N, int K) {
	if (K * 2 > N)
	{
		return 0;
	}
	if (K == 1)
	{
		return N;
	}

	if (dp[N][K] != 0)
	{
		return dp[N][K];
	}

	return dp[N][K] = (DFS(N - 2, K - 1) + DFS(N - 1, K)) % 1000000003;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	cout << DFS(N, K);
}