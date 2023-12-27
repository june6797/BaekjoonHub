#include <iostream>
using namespace std;

long long int fib[2][2];
long long int i[2][2];
long long int temp[2][2];
void mul(long long int arr[2][2], long long int arr2[2][2]) {
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				temp[i][j] += (arr[i][k] * arr2[k][j]) % 1000000;
			}
			temp[i][j] %= 1000000;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			arr[i][j] = temp[i][j];
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fib[0][0] = 1;
	fib[0][1] = 1;
	fib[1][0] = 1;
	fib[1][1] = 0;

	i[0][0] = 1;
	i[0][1] = 0;
	i[1][0] = 0;
	i[1][1] = 1;

	long long int n;
	cin >> n;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			mul(i, fib);
			n--;
		}
		else
		{
			mul(fib, fib);
			n /= 2;
		}
	}
	cout << i[0][1];
}