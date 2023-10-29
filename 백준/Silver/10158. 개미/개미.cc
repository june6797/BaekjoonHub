#include <iostream>
using namespace std;

int main() {
	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;
	int x = p + t;
	int y = q + t;
	if ((x / w) % 2 == 1)
	{
		x = w - (x % w);
	}
	else {
		x = x % w;
	}
	if ((y / h) % 2 == 1)
	{
		y = h - (y % h);
	}
	else {
		y = y % h;
	}
	cout << x << " " << y;
}
