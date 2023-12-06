#include <iostream>
using namespace std;

long long int arr[201][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j > 100)
			{
				continue;
			}
			if (j == 0 || j == i)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
				if (arr[i][j] > 1000000000)
				{
					arr[i][j] = 1000000000;
				}
			}
		}
	}
	if (K > arr[N + M][M])
	{
		cout << "-1";
	}
	else
	{
		while (N != 0 || M != 0)
		{
			if (K <= arr[N + M - 1][M])
			{
				cout << "a";
				N--;
			}
			else
			{
				cout << "z";
				K -= arr[N + M - 1][M];
				M--;
			}
		}
	}
}