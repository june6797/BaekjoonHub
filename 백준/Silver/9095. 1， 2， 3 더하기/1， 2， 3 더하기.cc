#include <iostream>
#include <string>
using namespace std;

int arr[12];

int main() {
	int T;
	cin >> T;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= 10; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		cout << arr[n] << "\n";
	}
}