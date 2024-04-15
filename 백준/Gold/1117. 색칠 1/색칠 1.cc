#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll w, h, f, c, x1, y1, x2, y2;
	cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;
	ll k = (x2 - x1) * (y2 - y1) * (c + 1);
	if (w/2 >= f)
	{
		if (f >= x1)
		{
			if (f >= x2)
			{
				k += (x2 - x1) * (y2 - y1) * (c + 1);
			}
			else
			{
				k += (f - x1) * (y2 - y1) * (c + 1);
			}
		}
	}
	else
	{
		if (x1 <= w - f)
		{
			if (x2 <= w - f)
			{
				k += (x2 - x1) * (y2 - y1) * (c + 1);
			}
			else
			{
				k += (w - f - x1) * (y2 - y1) * (c + 1);
			}
		}
	}
	cout << w * h - k;
}