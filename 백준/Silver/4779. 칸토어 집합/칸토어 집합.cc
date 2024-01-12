#include <iostream>
#include <cmath>
using namespace std;

void draw(int start, int size) {
	if (size == 1)
	{
		if (start % 3 != 2)
		{
			cout << "-";
		}
		return;
	}
	draw(1, size / 3);
	for (int i = 1; i <= size / 3; i++)
	{
		cout << " ";
	}
	draw(1 + 2 * (size / 3), size / 3);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n)
	{
		int k = pow(3, n);
		draw(1, k);
		cout << "\n";
	}

}