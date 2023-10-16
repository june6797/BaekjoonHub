#include <iostream>

using namespace std;

int main() {
	int R, G, B;
	cin >> R >> G >> B;
	int ans = 0, check = 0, m = 0;
	ans = R / 3 + G / 3 + B / 3;
	if (R % 3 == 0)
	{
		check++;
	}
	if (G % 3 == 0)
	{
		check++;
	}
	m = max(R % 3, G % 3);
	if (B % 3 == 0)
	{
		check++;
	}
	m = max(m, B % 3);
	switch (check)
	{
	case 3:
	case 1:
	case 0:
		ans += m;
		break;
	case 2:
		ans += 1;
		break;
	default:
		break;
	}
	cout << ans;
}