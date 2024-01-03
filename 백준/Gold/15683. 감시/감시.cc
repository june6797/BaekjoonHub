#include <iostream>
#include <vector>
using namespace std;

int N, M;
int ans = 100;
vector<pair<int, int>> v;


void showright(int x, int y, int arr[8][8]) {
	for (int i = y + 1; i < M; i++)
	{
		if (arr[x][i] == 6)
		{
			break;
		}
		else if (arr[x][i] > 0 && arr[x][i] < 6)
		{
			continue;
		}
		else
		{
			arr[x][i] = 7;
		}
	}
}

void showleft(int x, int y, int arr[8][8]) {
	for (int i = y - 1; i >= 0; i--)
	{
		if (arr[x][i] == 6)
		{
			break;
		}
		else if (arr[x][i] > 0 && arr[x][i] < 6)
		{
			continue;
		}
		else
		{
			arr[x][i] = 7;
		}
	}
}

void showup(int x, int y, int arr[8][8]) {
	for (int i = x - 1; i >= 0; i--)
	{
		if (arr[i][y] == 6)
		{
			break;
		}
		else if (arr[i][y] > 0 && arr[i][y] < 6)
		{
			continue;
		}
		else
		{
			arr[i][y] = 7;
		}
	}
}

void showdown(int x, int y, int arr[8][8]) {
	for (int i = x + 1; i < N; i++)
	{
		if (arr[i][y] == 6)
		{
			break;
		}
		else if (arr[i][y] > 0 && arr[i][y] < 6)
		{
			continue;
		}
		else
		{
			arr[i][y] = 7;
		}
	}
}

void DFS(int cnt, int level, int board[8][8]) {
	if (cnt == level)
	{
		int temp = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == 0)
				{
					temp++;
				}
			}
		}
		ans = min(ans, temp);
		return;
	}
	int temp[8][8];
	int x = v[cnt].first;
	int y = v[cnt].second;
	int cctvnum = board[x][y];
	switch (cctvnum)
	{
	case 1:
		for (int t = 0; t < 4; t++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					temp[i][j] = board[i][j];
				}
			}
			if (t == 0)
			{
				showup(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
			else if (t == 1)
			{
				showright(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
			else if (t == 2)
			{
				showdown(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
			else if (t == 3)
			{
				showleft(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
		}
		break;
	case 2:
		for (int t = 0; t < 2; t++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					temp[i][j] = board[i][j];
				}
			}
			if (t == 0)
			{
				showup(x, y, temp);
				showdown(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
			else if (t == 1)
			{
				showright(x, y, temp);
				showleft(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
		}
		break;
	case 3:
		for (int t = 0; t < 4; t++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					temp[i][j] = board[i][j];
				}
			}
			if (t == 0)
			{
				showup(x, y, temp);
				showright(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
			else if (t == 1)
			{
				showright(x, y, temp);
				showdown(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
			else if (t == 2)
			{
				showdown(x, y, temp);
				showleft(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
			else if (t == 3)
			{
				showleft(x, y, temp);
				showup(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
		}
		break;
	case 4:
		for (int t = 0; t < 4; t++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					temp[i][j] = board[i][j];
				}
			}
			if (t == 0)
			{
				showup(x, y, temp);
				showright(x, y, temp);
				showdown(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
			else if (t == 1)
			{
				showright(x, y, temp);
				showdown(x, y, temp);
				showleft(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
			else if (t == 2)
			{
				showdown(x, y, temp);
				showleft(x, y, temp);
				showup(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
			else if (t == 3)
			{
				showleft(x, y, temp);
				showup(x, y, temp);
				showright(x, y, temp);
				DFS(cnt + 1, level, temp);
			}
		}
		break;
	case 5:

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				temp[i][j] = board[i][j];
			}
		}
		showup(x, y, temp);
		showright(x, y, temp);
		showdown(x, y, temp);
		showleft(x, y, temp);
		DFS(cnt + 1, level, temp);
		break;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[8][8];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 6)
			{
				v.push_back({ i, j });
			}
		}
	}
	DFS(0, v.size(), arr);
	cout << ans;
}