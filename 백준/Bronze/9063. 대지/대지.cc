#include <iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int xmax = -10001, ymax = -10001, xmin = 10001, ymin = 10001;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > xmax)
		{
			xmax = a;
		}
		if (a < xmin) {
			xmin = a;
		}
		if (b > ymax) {
			ymax = b;
		}
		if (b < ymin) {
			ymin = b;
		}
	}
	cout << (xmax - xmin) * (ymax - ymin);
}