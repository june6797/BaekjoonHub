#include <iostream>

using namespace std;

int main() {
	int N;
	int K;
	int X;
	int ans = 0;
	cin >> N >> K;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		arr[i] = X;
	}
	for (int i = 0; i < N; i++)
	{
		while (K >= arr[N - 1 - i])
		{
			K = K - arr[N - 1 - i];
			ans++;
		}
	}

	cout << ans;
	delete[] arr;
}