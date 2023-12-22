#include <iostream>
using namespace std;
typedef long long int lli;

lli CCW(lli x1, lli y1, lli x2, lli y2, lli x3, lli y3) {
	lli t = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	if (t > 0)
	{
		return 1;
	}
	else if (t < 0)
	{
		return -1;
	}
	return 0;
}
int main() {
	lli x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	lli abc = CCW(x1, y1, x2, y2, x3, y3);
	lli abd = CCW(x1, y1, x2, y2, x4, y4);
	lli cda = CCW(x3, y3, x4, y4, x1, y1);
	lli cdb = CCW(x3, y3, x4, y4, x2, y2);
	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (max(x1, x2) >= min(x3, x4) && max(x3, x4) >= min(x1, x2)
			&& max(y1, y2) >= min(y3, y4) && max(y3, y4) >= min(y1, y2))
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else if (abc * abd <= 0 && cda * cdb <= 0)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}