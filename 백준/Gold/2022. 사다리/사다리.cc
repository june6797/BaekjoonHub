#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;

using namespace std;

double x, y, c;
double solve(double mid) {
	double h1 = sqrt(x * x - mid * mid);
	double h2 = sqrt(y * y - mid * mid);
	return h1 * h2 / (h1 + h2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> x >> y >> c;
	double low = 0;
	double high = min(x, y);
	double ans = 0;
	while (high - low > 0.001)
	{
		double mid = (low + high) / 2;
		if (solve(mid) >= c)
		{
			ans = mid;
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	cout << ans;
}
