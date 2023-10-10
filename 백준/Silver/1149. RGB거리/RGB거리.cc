#include <iostream>
using namespace std;

int main() {
	int check = 0, n, r, g, b;
	int rgb[3] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> r >> g >> b;
		int checkr = rgb[0];
		int checkg = rgb[1];
		int checkb = rgb[2];

		rgb[0] = min(checkg + r, checkb + r);
		rgb[1] = min(checkr + g, checkb + g);
		rgb[2] = min(checkr + b, checkg + b);
	}
	int ans = min(rgb[0], rgb[1]);
	ans = min(ans, rgb[2]);
	cout << ans;
}