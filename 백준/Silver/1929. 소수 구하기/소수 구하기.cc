#include <iostream>
using namespace std;
int arr[1000001];

int main() {
	int M, N;
	cin >> M >> N;
	arr[1] = 1;
	for (int i = 2; i * i <= N; i++)
	{
		if (arr[i] == 0) {
			for (int j = i + i; j <= N; j = j + i)
			{
				arr[j] = 1;
			}
		}
	}
	for (int i = M; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			cout << i << "\n";
		}
	}
}