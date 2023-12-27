#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int small = 987654321, big = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		small = min(small, num);
		big = max(big, num);
	}
	cout << small * big;
}