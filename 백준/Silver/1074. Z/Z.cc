#include <iostream>
#include <cmath>
using namespace std;

void findw(int size, int r, int c, int& ans) {
	if (size == 1)
	{
		return;
	}
	int half = size / 2;
	if (r < half && c < half)
	{
		findw(half, r % half, c % half, ans);
	}
	else if (r < half && c >= half)
	{
		ans += half * half * 1;
		findw(half, r % half, c % half, ans);
	}
	else if (r >= half && c < half)
	{
		ans += half * half * 2;
		findw(half, r % half, c % half, ans);
	}
	else if (r >= half && c >= half)
	{
		ans += half * half * 3;
		findw(half, r % half, c % half, ans);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, r, c, ans = 0;
	cin >> n >> r >> c;
	int size = pow(2, n);
	findw(size, r, c, ans);
	cout << ans;
}