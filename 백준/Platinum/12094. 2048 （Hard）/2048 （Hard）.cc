#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int ans = 0;
int N;
int levelmax[10];
void move_board(int temp[21][21], int num) {
	if (num == 0)
	{
		for (int j = 0; j < N; j++)
		{
			int data = -1;
			int idx = -1;
			for (int i = 0; i < N; i++)
			{
				if (temp[i][j] != 0)
				{
					if (temp[i][j] == data)
					{
						temp[idx][j] = 2 * temp[idx][j];
						data = -1;
					}
					else
					{
						data = temp[i][j];
						idx++;
						temp[idx][j] = temp[i][j];
					}
				}
			}
			for (int i = idx + 1; i < N; i++)
			{
				temp[i][j] = 0;
			}
		}
	}
	else if (num == 1)
	{
		for (int i = 0; i < N; i++)
		{
			int data = -1;
			int idx = N;
			for (int j = N - 1; j >= 0; j--)
			{
				if (temp[i][j] != 0)
				{
					if (temp[i][j] == data)
					{
						temp[i][idx] = 2 * temp[i][idx];
						data = -1;
					}
					else
					{
						data = temp[i][j];
						idx--;
						temp[i][idx] = temp[i][j];
					}
				}
			}
			for (int j = idx - 1; j >= 0; j--)
			{
				temp[i][j] = 0;
			}
		}
	}
	else if (num == 2)
	{
		for (int j = 0; j < N; j++)
		{
			int data = -1;
			int idx = N;
			for (int i = N - 1; i >= 0; i--)
			{
				if (temp[i][j] != 0)
				{
					if (temp[i][j] == data)
					{
						temp[idx][j] = 2 * temp[idx][j];
						data = -1;
					}
					else
					{
						data = temp[i][j];
						idx--;
						temp[idx][j] = temp[i][j];
					}
				}
			}
			for (int i = idx - 1; i >= 0; i--)
			{
				temp[i][j] = 0;
			}
		}
	}
	else if (num == 3)
	{
		for (int i = 0; i < N; i++)
		{
			int data = -1;
			int idx = -1;
			for (int j = 0; j < N; j++)
			{
				if (temp[i][j] != 0)
				{
					if (temp[i][j] == data)
					{
						temp[i][idx] = 2 * temp[i][idx];
						data = -1;
					}
					else
					{
						data = temp[i][j];
						idx++;
						temp[i][idx] = temp[i][j];
					}
				}
			}
			for (int j = idx + 1; j < N; j++)
			{
				temp[i][j] = 0;
			}
		}
	}
}

void DFS(int cnt, int board[21][21]) {
	if (cnt == 10)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ans = max(ans, board[i][j]);
			}
		}
		return;
	}
	int temp[21][21];
	int maxtemp = 0;
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < N; k++)
		{
			maxtemp = max(maxtemp, board[j][k]);
			ans = max(ans, board[j][k]);
		}
	}
	for (int j = 0; j < 10 - cnt; j++)
	{
		maxtemp *= 2;
	}
	if (maxtemp > ans)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					temp[j][k] = board[j][k];
				}
			}
			move_board(temp, i);
			bool diff = false;
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					if (temp[j][k] != board[j][k])
					{
						diff = true;
						break;
					}
				}
			}
			if (diff)
			{
				DFS(cnt + 1, temp);
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int board[21][21];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	DFS(0, board);
	cout << ans;
}