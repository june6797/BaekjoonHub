#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int map[51][51];
int visit[51][51];
queue<pair<int, int>> q;

int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

vector <int> ans;

void bfs(int x, int y, int M, int N) {
	int cnt = 1;
	map[x][y] = 0;
	
	q.push({ x, y });
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x_new = x + x_move[i];
			int y_new = y + y_move[i];
			if ((0<= x_new && x_new < N)&& (0 <= y_new && y_new < M)
				&& map[x_new][y_new] == 1)
			{
				map[x_new][y_new] = 0;
				q.push({ x_new, y_new });
				cnt++;
			}
		}
	}
	ans.push_back(cnt);
}


int main() {
	int T, M, N, K , a, b;
	string num;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int anum = 0;
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> a >> b;
			map[b][a] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] != 0)
				{
					anum++;
					bfs(i, j, M, N);
				}
			}
		}
		cout << anum << "\n";
	}
}
