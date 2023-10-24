#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		long long int x, y, ans = 0;
		cin >> x >> y;
		int dis = y - x;
		int k = 1;
		while (dis > 0)
		{
			if (dis - 2 * k >= 0)
			{
				dis -= 2 * k;
				ans += 2;
			}
			else if (dis - k >= 0)
			{
				dis -= k;
				ans++;
			}
			else
			{
				dis -= k - 1;
				ans++;
			}

			k++;
		}


		cout << ans << "\n";
	}
}