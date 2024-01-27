#include <iostream>
using namespace std;
long long int arr[36];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= 35; i++)
	{
		for (int j = 0; j < i; j++)
		{
			arr[i] += (arr[j] * arr[i - j - 1]);
		}
	}
	cout << arr[n];
}