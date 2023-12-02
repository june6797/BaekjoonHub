#include <iostream>
using namespace std;

int arr[5][5];
int temp[5][5];
int ans[5][5];
void mul(int x[5][5], int y[5][5], int N) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				temp[i][j] += (x[i][k] * y[k][j]);
			}
			temp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			x[i][j] = temp[i][j];
		}
	}

}
int main() {
	long long int N, B;
	cin >> N >> B;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
		ans[i][i] = 1;
	}

	while (B > 0)
	{
		if (B % 2 == 1)
		{
			mul(ans, arr, N);
			B--;
		}
		else
		{
			mul(arr, arr, N);
			B /= 2;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}