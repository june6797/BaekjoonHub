#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int ans = 0;
int N;

void move_board(int temp[21][21], int num) {
	if (num == 0)
	{
		for (int i = 0; i < N; i++)
		{
			deque<int> v;
			deque<int> d;
			for (int j = 0; j < N; j++)
			{
				if (temp[j][i] != 0)
				{
					v.push_back(temp[j][i]);
				}
			}
			while (v.size() > 1)
			{
				int first = v.front();
				v.pop_front();
				if (first == v.front())
				{
					d.push_back(first * 2);
					v.pop_front();
				}
				else
				{
					d.push_back(first);
				}
			}
			if (v.size() == 1)
			{
				d.push_back(v.front());
			}
			while (d.size() != N)
			{
				d.push_back(0);
			}
			for (int j = 0; j < N; j++)
			{
				temp[j][i] = d[j];
			}
		}
	}
	else if (num == 1)
	{
		for (int i = 0; i < N; i++)
		{
			deque<int> v;
			deque<int> d;
			for (int j = N - 1; j >= 0; j--)
			{
				if (temp[i][j] != 0)
				{
					v.push_back(temp[i][j]);
				}
			}
			while (v.size() > 1)
			{
				int first = v.front();
				v.pop_front();
				if (first == v.front())
				{
					d.push_back(first * 2);
					v.pop_front();
				}
				else
				{
					d.push_back(first);
				}
			}
			if (v.size() == 1)
			{
				d.push_back(v.front());
			}
			while (d.size() != N)
			{
				d.push_back(0);
			}
			for (int j = 0; j < N; j++)
			{
				temp[i][N - 1 - j] = d[j];
			}
		}
	}
	else if (num == 2)
	{
		for (int i = 0; i < N; i++)
		{

			deque<int> v;
			deque<int> d;
			for (int j = N - 1; j >= 0; j--)
			{
				if (temp[j][i] != 0)
				{
					v.push_back(temp[j][i]);
				}
			}
			while (v.size() > 1)
			{
				int first = v.front();
				v.pop_front();
				if (first == v.front())
				{
					d.push_back(first * 2);
					v.pop_front();
				}
				else
				{
					d.push_back(first);
				}
			}
			if (v.size() == 1)
			{
				d.push_back(v.front());
			}
			while (d.size() != N)
			{
				d.push_back(0);
			}
			for (int j = 0; j < N; j++)
			{
				temp[N - 1 - j][i] = d[j];
			}
		}
	}
	else if (num == 3)
	{
		for (int i = 0; i < N; i++)
		{

			deque<int> v;
			deque<int> d;
			for (int j = 0; j < N; j++)
			{
				if (temp[i][j] != 0)
				{
					v.push_back(temp[i][j]);
				}
			}
			while (v.size() > 1)
			{
				int first = v.front();
				v.pop_front();
				if (first == v.front())
				{
					d.push_back(first * 2);
					v.pop_front();
				}
				else
				{
					d.push_back(first);
				}
			}
			if (v.size() == 1)
			{
				d.push_back(v.front());
			}
			while (d.size() != N)
			{
				d.push_back(0);
			}
			for (int j = 0; j < N; j++)
			{
				temp[i][j] = d[j];
			}
		}
	}
}

void DFS(int cnt, int level, int board[21][21]) {
	if (cnt == level)
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
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				temp[j][k] = board[j][k];
				maxtemp = max(maxtemp, board[i][j]);
			}
		}
		move_board(temp, i);
		bool diff = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (temp[i][j] != board[i][j])
				{
					diff = true;
				}
			}
		}
		for (int i = 0; i < N - cnt; i++)
		{
			maxtemp *= 2;
		}
		
		DFS(cnt + 1, level, temp);
		
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
	DFS(0, 5, board);
	cout << ans;
}