#include <iostream>
using namespace std;

long long int dp[100001][2];
long long int mul(long long int x, long long int y, long long int p) {
	long long ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}
int main() {
	long long int N, K;
	cin >> N >> K;
	dp[0][1] = N;
	dp[1][0] = N - 1;
	dp[1][1] = N * (N - 1) / 2;
	for (int i = 2; i <= K; i++)
	{
		dp[i][0] = ((dp[i - 1][0] - 1) * 2) % 1000000007;
		long long int a = mul(2, 1000000005, 1000000007);
		dp[i][1] = ((dp[i - 1][1] % 1000000007) * ((dp[i][0] * a) % 1000000007)) % 1000000007;
	}
	cout << dp[K][1];
}