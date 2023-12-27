#include <iostream>
using namespace std;

int day[12] = { 31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y;
	cin >> x >> y;
	int d = 0;
	for (int i = 1; i <= x - 1; i++)
	{
		d += day[i - 1];
	}
	d += y;
	int a = d % 7;
	switch (a)
	{
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	default:
		break;
	}
}