#include <iostream>
using namespace std;
int arr[16][16][3];
int w[16][16];

void pipe(int N) {
	arr[0][1][0] = 1;
	for (int i = 2; i < N; i++)
	{
		if (w[0][i] == 0)
		{
			arr[0][i][0] = arr[0][i - 1][0];
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (w[i][j] == 0)
			{
				arr[i][j][0] = arr[i][j - 1][0] + arr[i][j - 1][1];
				arr[i][j][2] = arr[i - 1][j][2] + arr[i - 1][j][1];
			}
			if (w[i][j] == 0 && w[i - 1][j] == 0 && w[i][j - 1] == 0)
			{
				arr[i][j][1] = arr[i - 1][j - 1][0] + arr[i - 1][j - 1][1]
					+ arr[i - 1][j - 1][2];
			}
		}
	}

	cout << arr[N - 1][N - 1][0] + arr[N - 1][N - 1][1]
		+ arr[N - 1][N - 1][2];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> w[i][j];
		}
	}
	pipe(N);
}