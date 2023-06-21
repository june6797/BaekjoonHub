#include <iostream>
using namespace std;
int main() {
	int x;
	int y;

	cin >> x >> y;
	if (x == 0)
	{
		if (y < 45)
		{
			x = 23;
			y = y + 15;
		}
		else if (y >= 45)
		{
			y = y - 45;
		}


	}
	else {
		if (y < 45)
		{
			x = x - 1;
			y = y + 15;
		}
		else if (y >= 45)
		{
			y = y - 45;
		}
	}

	cout << x << " " << y;

}