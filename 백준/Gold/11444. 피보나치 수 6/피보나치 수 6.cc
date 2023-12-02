#include <iostream>
using namespace std;

long long int arr[2][2];
long long int temp[2][2];
long long int ans[2][2];
void mul(long long int x[2][2], long long int y[2][2]) {
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				temp[i][j] += (x[i][k] * y[k][j]) % 1000000007;
			}
			temp[i][j] %= 1000000007;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			x[i][j] = temp[i][j];
		}
	}

}
int main() {
	long long int N;
	cin >> N;
	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 0;

	ans[0][0] = 1;
	ans[0][1] = 0;
	ans[1][0] = 0;
	ans[1][1] = 1;

	while (N > 0)
	{
		if (N % 2 == 1)
		{
			mul(ans, arr);
			N--;
		}
		else
		{
			mul(arr, arr);
			N /= 2;
		}
	}
	cout << ans[1][0];
}