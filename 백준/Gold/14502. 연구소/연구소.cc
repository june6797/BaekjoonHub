#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[9][9];
vector <pair<int, int>> safe;
vector <pair<int, int>> virus;
vector <pair<int, int>> wall;
queue<pair<int, int>> q;

int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

void BFS(int x, int y, int N, int M) {
	q.push({ x, y });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x_next = x + x_move[i];
			int y_next = y + y_move[i];
			if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < M
				&& arr[x_next][y_next] == 0)
			{
				arr[x_next][y_next] = 2;
				q.push({ x_next, y_next });
			}
		}
	}
}



int main() {
	int N, M, num, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			arr[i][j] = num;
			if (num == 0)
			{
				safe.push_back({ i, j });
			}
			else if (num == 1)
			{
				wall.push_back({ i, j });
			}
			else if (num == 2)
			{
				virus.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < safe.size() - 2; i++)
	{
		for (int j = i + 1; j < safe.size() - 1; j++)
		{
			for (int k = j + 1; k < safe.size(); k++)
			{
				arr[safe[i].first][safe[i].second] = 1;
				arr[safe[j].first][safe[j].second] = 1;
				arr[safe[k].first][safe[k].second] = 1;

				for (int m = 0; m < virus.size(); m++)
				{
					BFS(virus[m].first, virus[m].second, N, M);
				}
				int cnt = 0;
				for (int a = 0; a < N; a++)
				{
					for (int b = 0; b < M; b++)
					{
						if (arr[a][b] == 0)
						{
							cnt++;
						}
					}
				}
				if (ans < cnt)
				{
					ans = cnt;
				}

				for (int s = 0; s < safe.size(); s++) {
					arr[safe[s].first][safe[s].second] = 0;
				}
			}
		}
	}

	cout << ans;
}
