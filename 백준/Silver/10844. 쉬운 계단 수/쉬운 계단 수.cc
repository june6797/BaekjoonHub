#include <iostream>
#define b 1000000000
using namespace std;

int arr[101][10];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i < 10; i++)
	{
		arr[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				arr[i][j] = arr[i - 1][1] % b;
			}
			else if (j == 9)
			{
				arr[i][j] = arr[i - 1][8] % b;
			}
			else
			{
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % b;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans = (ans + arr[N][i]) % b;
	}
	cout << ans;
}