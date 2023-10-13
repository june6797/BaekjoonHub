#include <iostream>
using namespace std;

int arr[101][101];
void dfs(int start, int n, int first) {
	for (int i = 1; i <= n; i++)
	{
		if (i == start)
		{

		}
		else if (arr[start][i] == 1)
		{
			if (arr[first][i] == 0 && start != first)
			{
				arr[first][i] = 1;
				dfs(i, n, first);
			}
			else if (start == first)
			{
				dfs(i, n, first);
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		dfs(i, n, i);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

