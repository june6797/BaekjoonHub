#include <iostream>
#include <queue>
using namespace std;

int arr[501][501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	//직선 가로
	for (int i = 0; i < N - 3; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp = arr[i][j] + arr[i + 1][j]
				+ arr[i + 2][j] + arr[i + 3][j];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}
	//직선 세로
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 3; j++)
		{
			int temp = arr[i][j] + arr[i][j + 1]
				+ arr[i][j + 2] + arr[i][j + 3];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}
	//사격형
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int temp = arr[i][j] + arr[i][j + 1]
				+ arr[i + 1][j] + arr[i + 1][j + 1];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}
	//주황색 1
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int temp = arr[i][j] + arr[i + 1][j]
				+ arr[i + 2][j] + arr[i + 2][j + 1];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}
	//주황색 2
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			int temp = arr[i][j] + arr[i + 1][j]
				+ arr[i][j + 1] + arr[i][j + 2];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}
	//주황색 3
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int temp = arr[i][j] + arr[i][j + 1]
				+ arr[i + 1][j + 1] + arr[i + 2][j + 1];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//주황색 4
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			int temp = arr[i + 1][j] + arr[i + 1][j + 1]
				+ arr[i + 1][j + 2] + arr[i][j + 2];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//주황색 뒤집기 1
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int temp = arr[i][j + 1] + arr[i + 1][j + 1]
				+ arr[i + 2][j + 1] + arr[i + 2][j];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}
	//주황색 뒤집기 2
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			int temp = arr[i][j] + arr[i + 1][j]
				+ arr[i + 1][j + 1] + arr[i + 1][j + 2];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}
	//주황색 뒤집기 3
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int temp = arr[i][j] + arr[i][j + 1]
				+ arr[i + 1][j] + arr[i + 2][j];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//주황색 뒤집기 4
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			int temp = arr[i][j] + arr[i][j + 1]
				+ arr[i][j + 2] + arr[i + 1][j + 2];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//초록색 1
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int temp = arr[i][j] + arr[i + 1][j]
				+ arr[i + 1][j + 1] + arr[i + 2][j + 1];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//초록색 2
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			int temp = arr[i + 1][j] + arr[i + 1][j + 1]
				+ arr[i][j + 1] + arr[i][j + 2];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//초록색 3
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int temp = arr[i][j + 1] + arr[i + 1][j + 1]
				+ arr[i + 1][j] + arr[i + 2][j];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//초록색 4
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			int temp = arr[i][j] + arr[i][j + 1]
				+ arr[i + 1][j + 1] + arr[i + 1][j + 2];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//핑크색 1
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			int temp = arr[i][j] + arr[i][j + 1]
				+ arr[i][j + 2] + arr[i + 1][j + 1];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//핑크색 2
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int temp = arr[i + 1][j] + arr[i][j + 1]
				+ arr[i + 1][j + 1] + arr[i + 2][j + 1];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//핑크색 3
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			int temp = arr[i][j + 1] + arr[i + 1][j]
				+ arr[i + 1][j + 1] + arr[i + 1][j + 2];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	//핑크색 4
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int temp = arr[i][j] + arr[i + 1][j]
				+ arr[i + 2][j] + arr[i + 1][j + 1];
			if (temp > ans)
			{
				ans = temp;
			}
		}
	}

	cout << ans;


}