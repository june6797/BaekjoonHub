#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
			{
				cout << "-1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else
		{
			int a = (x1 - x2) * (x1 - x2);
			int b = (y1 - y2) * (y1 - y2);
			double r = sqrt(a + b);
			if (r > r1 + r2)
			{
				cout << "0\n";
			}
			else if (r == r1 + r2)
			{
				cout << "1\n";
			}
			else if (r < r1 + r2)
			{
				if (r > abs(r1 - r2))
				{
					cout << "2\n";
				}
				else if (r == abs(r1 - r2))
				{
					cout << "1\n";
				}
				else if (r < abs(r1 - r2))
				{
					cout << "0\n";
				}
			}
		}
	}
}