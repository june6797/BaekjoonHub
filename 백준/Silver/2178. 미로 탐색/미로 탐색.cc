#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<pair <int, int>> q;
int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

void BFS(int N, int M, int x, int y, int** arr, int** visit, int** dist) {
	visit[x][y] = 1;
	q.push({ x, y });
	dist[x][y]++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x_check = x + x_move[i];
			int y_check = y + y_move[i];
			if ((0 <= x_check && x_check < N) && (0 <= y_check && y_check < M)
				&& visit[x_check][y_check] == 0 && arr[x_check][y_check] == 1) {

				visit[x_check][y_check] = 1;
				q.push({ x_check,y_check });
				dist[x_check][y_check] = dist[x][y] + 1;
			}
		}
	}
}

int main() {

	int N, M;
	string num;

	cin >> N >> M;

	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
	}

	int** visit = new int* [N];
	for (int i = 0; i < N; i++)
	{
		visit[i] = new int[M];
	}

	int** dist = new int* [N];
	for (int i = 0; i < N; i++)
	{
		dist[i] = new int[M];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = num.at(j) - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dist[i][j] = 0;
		}
	}

	BFS(N, M, 0, 0, arr, visit, dist);

	cout << dist[N - 1][M - 1];

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	for (int i = 0; i < N; i++)
	{
		delete[] visit[i];
	}
	delete[] visit;

	for (int i = 0; i < N; i++)
	{
		delete[] dist[i];
	}
	delete[] dist;
}
