#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26];
int visit[26][26];
queue<pair<int, int>> q;

int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

int anum;
vector <int> ans;

void BFS(int x, int y, int N) {
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
			if ((0<= x_new && x_new < N)&& (0 <= y_new && y_new < N)
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
	int N;
	string num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = num.at(j) - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] != 0)
			{
				anum++;
				BFS(i, j, N);
			}
		}
	}

	cout << anum <<"\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < anum; i++)
	{
		cout << ans[i] <<"\n";
	}
}
