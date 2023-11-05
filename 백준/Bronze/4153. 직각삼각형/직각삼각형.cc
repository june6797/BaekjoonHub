#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	while (a != 0 || b != 0 || c != 0)
	{
		int x = a * a;
		int y = b * b;
		int z = c * c;
		if (x == y + z || y == x + z || z == x + y)
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
		cin >> a >> b >> c;
	}
}