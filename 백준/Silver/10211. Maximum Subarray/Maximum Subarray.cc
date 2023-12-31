#include <iostream>
#include <unordered_map>
using namespace std;

int arr[1001];
int dp[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> arr[i];
		}
		int ans = -1001;
		for (int i = 1; i <= N; i++)
		{
			int s = arr[i];
			ans = max(ans, s);
			for (int j = i + 1; j <= N; j++)
			{
				s += arr[j];
				ans = max(ans, s);
			}
		}
		cout << ans << "\n";

	}
}