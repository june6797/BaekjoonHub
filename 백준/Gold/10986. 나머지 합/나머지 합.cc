#include <iostream>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	long int* arr = new long int[N + 1];
	long int* count = new long int[M + 1];
	long int ans = 0;
	for (int i = 0; i <= N; i++)
	{
		arr[i] = 0;
	}
	for (int i = 0; i <= M; i++)
	{
		count[i] = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}
	for (int i = 1; i <= N; i++)
	{
		arr[i] = arr[i] % M;
		if (arr[i] == 0)
		{
			ans++;
		}
		count[arr[i]]++;
	}

	for (int i = 0; i < M; i++)
	{
		if (count[i] > 1)
		{
			ans = ans + count[i] * (count[i] - 1) / 2;
		}
	}
	cout << ans << "\n";

	delete[] count;
	delete[] arr;
}