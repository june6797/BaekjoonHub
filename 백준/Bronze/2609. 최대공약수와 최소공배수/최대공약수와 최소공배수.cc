#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}
int main() {
	int a, b;
	cin >> a >> b;
	int x = gcd(a, b);
	int y = (a / x) * b;
	cout << x << "\n" << y;
}