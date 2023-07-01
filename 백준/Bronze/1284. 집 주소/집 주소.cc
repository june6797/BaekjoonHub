#include <iostream>
#include <string>
using namespace std;
int main() {
	int N;
	cin >> N;
	while (N != 0) {
		int a = N % 10;
		int k = N / 10;
		int ans = 0;
		while (k != 0) {
			ans++;
			if (a == 0)
			{
				ans = ans + 4;

			}
			else if (a == 1)
			{
				ans = ans + 2;
			}
			else
			{
				ans = ans + 3;
			}
			a = k % 10;
			k = k / 10;
		}
		ans++;
		if (a == 0)
		{
			ans = ans + 4;
		}
		else if (a == 1)
		{
			ans = ans + 2;
		}
		else
		{
			ans = ans + 3;
		}
		ans++;
		cout << ans << "\n";
		cin >> N;
	}

}