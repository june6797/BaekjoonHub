#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, cnt = 1, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		if (num != cnt)
		{
			ans++;
		}
		cnt++;
	}
	cout << ans;
}