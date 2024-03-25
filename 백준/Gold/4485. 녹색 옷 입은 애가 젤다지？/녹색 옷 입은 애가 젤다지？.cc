#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
typedef long long int ll;
using namespace std;

int arr[125][125];
int sum[125][125];
int N;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
	greater<pair<int, pair<int, int>>>> pq;
void Dijkstra(int x, int y) {
	sum[x][y] = arr[x][y];
	pq.push({ sum[x][y], {x, y} });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int tx = pq.top().second.first;
		int ty = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
				arr[nx][ny] + cost < sum[nx][ny])
			{
				sum[nx][ny] = arr[nx][ny] + cost;
				pq.push({ sum[nx][ny], {nx, ny} });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 1;
	while (1)
	{
		cin >> N;
		if (N == 0)
		{
			exit(0);
		}
		memset(arr, -1, sizeof(arr));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				sum[i][j] = 987654321;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}
		Dijkstra(0, 0);
		cout << "Problem " << cnt << ": " << sum[N - 1][N - 1] << "\n";
		cnt++;
	}
}

