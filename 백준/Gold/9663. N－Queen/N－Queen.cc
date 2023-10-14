#include <iostream>
using namespace std;
int arr[16];

void queendfs(int x, int n, int& ans) {
	if (x == n + 1) {
		ans++;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			arr[x] = i;
			bool flag = true;
			for (int j = 1; j < x; j++)
			{
				if (arr[x] == arr[j] || arr[x] - arr[j] == x - j
					|| arr[j] - arr[x] == x - j)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				queendfs(x + 1, n, ans);
			}
		}

	}
}

int main() {
	int n, ans = 0;
	cin >> n;
	queendfs(1, n, ans);
	cout << ans;
}
