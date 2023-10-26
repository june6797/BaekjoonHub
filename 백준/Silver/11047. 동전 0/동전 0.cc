#include <iostream>
using namespace std;
int arr[10];

int main() {
	int N, K, ans = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (K >= arr[i])
		{
			ans += K / arr[i];
			K = K % arr[i];
		}
	}
	cout << ans;

}