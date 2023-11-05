#include <iostream>
using namespace std;

int arr[501][501];
int main() {
	int N, M, B;
	cin >> N >> M >> B;
	int low = 1000, high = -1, sum = 0, ans = 1234567890;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (low > arr[i][j])
			{
				low = arr[i][j];
			}
			if (high < arr[i][j])
			{
				high = arr[i][j];
			}
			sum += arr[i][j];
		}
	}
	int m = (sum + B) / (M * N);
	if (m > high)
	{
		m = high;
	}
	for (int c = low; c <= m; c++)
	{
		int temp = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] < c)
				{
					temp += c - arr[i][j];
				}
				else
				{
					temp += 2 * (arr[i][j] - c);
				}
			}
		}
		if (temp <= ans)
		{
			ans = temp;
			high = c;
		}
	}

	cout << ans << " " << high;
}