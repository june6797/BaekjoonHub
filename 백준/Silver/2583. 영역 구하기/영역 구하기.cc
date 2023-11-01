#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cnt;
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
int arr[1001][1001];
vector<int> v;
queue<pair<int, int>> q;



void BFS(int x, int y, int M, int N) {
	arr[x][y] = 1;
	q.push({ x, y });
	cnt++;
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = a + x_move[i];
			int ny = b + y_move[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N
				&& arr[nx][ny] == 0)
			{
				arr[nx][ny] = 1;
				q.push({ nx, ny });
				cnt++;
			}
		}
	}
}

int main() {
	int M, N, K;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
				arr[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)
			{
				BFS(i, j, M, N);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}
