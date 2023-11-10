#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				arr[i][j] = 123456789;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a][b] == 0)
		{
			arr[a][b] = c;
		}
		else
		{
			if (c < arr[a][b])
			{

				arr[a][b] = c;
			}
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 123456789)
			{
				cout << "0 ";
			}
			else
			{
				cout << arr[i][j] << " ";
			}
		}
		cout << "\n";
	}
}