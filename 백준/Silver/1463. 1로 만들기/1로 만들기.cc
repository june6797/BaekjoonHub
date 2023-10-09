#include <iostream>
#include <climits>
using namespace std;

int arr[1000001];

int main() {
	int n;
	cin >> n;
	arr[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int three = INT_MAX, two = INT_MAX, one = INT_MAX;
		if (i % 3 == 0) {
			three = arr[i / 3];
		}

		if (i % 2 == 0) {
			two = arr[i / 2];
		}

		one = arr[i - 1];
		int check = min(three, two);

		arr[i] = min(check, one) + 1;
	}

	cout << arr[n];
}