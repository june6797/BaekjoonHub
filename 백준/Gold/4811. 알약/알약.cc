#include <iostream>
using namespace std;

long long int dp[31][31];

long long int DFS(int w, int h) {
	if (w == 0)
	{
		return 1;
	}
	if (h == -1)
	{
		return 0;
	}
	if (dp[w][h] != 0)
	{
		return dp[w][h];
	}
	dp[w][h] = DFS(w - 1, h + 1) + DFS(w, h - 1);
	return dp[w][h];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	DFS(30, 0);
	while (true)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			break;
		}
		else
		{
			cout << dp[num][0] << "\n";
		}
	}
}