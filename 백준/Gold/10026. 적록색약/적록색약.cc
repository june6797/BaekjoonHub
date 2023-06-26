#include <iostream>
#include <queue>
using namespace std;

char arr[101][101];
char arr2[101][101];
queue <pair<int, int>> q;
int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

void BFS(int x, int y, int N) {
	q.push({ x, y });
	char a = arr[x][y];
	arr[x][y] = '0';
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x_next = x + x_move[i];
			int y_next = y + y_move[i];
			if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < N
				&& arr[x_next][y_next] == a)
			{
				q.push({ x_next, y_next });
				arr[x_next][y_next] = '0';
			}
		}
	}
}

int main() {
	int N, ans1 = 0, ans2 = 0;
	string col;
	cin >> N;

	for (int i = 0; i < N; i++)
	{

		cin >> col;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = col.at(j);
			if (col.at(j) == 'G')
			{
				arr2[i][j] = 'R';
			}
			else
			{
				arr2[i][j] = col.at(j);
			}
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != '0')
			{
				BFS(i, j, N);
				ans1++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = arr2[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != '0')
			{
				BFS(i, j, N);
				ans2++;
			}
		}
	}
	cout << ans1 << " " << ans2;
}