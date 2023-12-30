#include <iostream>
using namespace std;

int dp[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	dp[0] = 1;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = i; j <= 10000; j++)
		{
			dp[j] += dp[j - i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}
}