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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << a * b / gcd(a, b) << "\n";
	}
}