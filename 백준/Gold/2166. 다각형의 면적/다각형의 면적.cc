#include <iostream>
using namespace std;

double dot[10001][2];
double CCW(double x1, double y1, double x2, double y2, double x3, double y3) {
	double t = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	return t;
}

int main() {
	int N;
	cin >> N;
	double ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> dot[i][0] >> dot[i][1];
	}
	dot[N][0] = dot[0][0];
	dot[N][1] = dot[0][1];
	for (int i = 0; i < N; i++)
	{
		ans += CCW(0, 0, dot[i][0], dot[i][1], dot[i + 1][0], dot[i + 1][1]);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans) / 2.0;
}