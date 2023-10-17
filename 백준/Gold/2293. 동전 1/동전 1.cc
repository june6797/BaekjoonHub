#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001];
int coin[101];
vector <int> v;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		coin[i] = num;
	}

	for (int i = 0; i < n; i++)
	{
		if (coin[i] <= k)
		{
			dp[coin[i]]++;
			for (int j = coin[i] + 1; j <= k; j++)
			{
				dp[j] += dp[j - coin[i]];
			}
		}
	}
    cout << dp[k] << "\n";

}