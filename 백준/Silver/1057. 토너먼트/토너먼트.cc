#include <iostream>

using namespace std;

int main() {
	int N, a, b;
	cin >> N >> a >> b;
	int ans = 0;
	while (a != b)
	{
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		ans++;
	}
	cout << ans;
}
