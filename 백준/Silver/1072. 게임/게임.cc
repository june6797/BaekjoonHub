#include <iostream>
using namespace std;


int main() {
	long long int X, Y;
	cin >> X >> Y;
	int Z = 100 * Y / X;
	if (Z >= 99) {
		cout << -1;
	}
	else
	{
		int l = 0, r = 1000000000;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int c = (Y + mid) * 100 / (X + mid);
			if (Z < c)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		cout << l;
	}
}
