#include <iostream>
using namespace std;
int arr[101][101];

int main() {
	for (int i = 1; i < 101; i++)
	{
		for (int j = 1; j < 101; j++)
		{
			if (i != j)
			{
				arr[i][j] = 123456789;
			}
		}
	}
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}

	int ans = 0, check = 1234567890;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= N; j++)
		{
			sum += arr[i][j];
		}
		if (sum < check)
		{
			check = sum;
			ans = i;
		}
	}
	cout << ans;
}
