#include <iostream>
using namespace std;
int arr[1001][1001];

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i < 1001; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			else if (j == i)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 10007;
			}
		}
	}
	cout << arr[N][K];
}
