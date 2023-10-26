#include <iostream>
using namespace std;
int arr[1001][10];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i <= 9; i++)
	{
		arr[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		arr[i][0] = arr[i - 1][0];
		for (int j = 1; j <= 9; j++)
		{
			arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % 10007;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans += arr[N][i];
	}
	cout << ans % 10007;
}