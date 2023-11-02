#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, ans = 0;
	cin >> a >> b >> c;
	for (int i = 1; i < 123456789; i++)
	{
		bool flag = false;
		if (a % 15 == 0) {
			a = 0;
		}
		if (b % 28 == 0) {
			b = 0;
		}
		if (c % 19 == 0) {
			c = 0;
		}
		if ((i % 15 == a) && (i % 28 == b) && (i % 19 == c))
		{
			flag = true;
		}
		if (flag) {
			ans = i;
			break;
		}
	}
	cout << ans;
}