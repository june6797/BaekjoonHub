#include <iostream>
using namespace std;

int ans[50001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < 50001; i++)
	{
		ans[i] = 1234567890;
	}
	for (int i = 1; i < 50001; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			ans[i] = min(ans[i], ans[i - j * j] + 1);
		}
	}
	cout << ans[n];
}