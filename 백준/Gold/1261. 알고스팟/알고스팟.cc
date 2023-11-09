#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int arr[100][100];
int visit[101][101];
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
int ans;
vector<pair<int, int>> q[1000];
void BFS(int x, int y, int z, int M, int N) {
	visit[x][y] = 1;
	q[z].push_back({ x, y });
	for (int i = 0; i < 1000; i++)
	{
		while (!q[i].empty())
		{
			int a = q[i].front().first;
			int b = q[i].front().second;
			int c = i;
			q[i].erase(q[i].begin());
			if (a == M - 1 && b == N - 1)
			{
				ans = i;
				return;
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = a + x_move[i];
				int ny = b + y_move[i];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N
					&& visit[nx][ny] == 0)
				{
					visit[nx][ny] = 1;
					if (arr[nx][ny] == 0)
					{
						q[c].push_back({ nx, ny });
					}
					else if (arr[nx][ny] == 1)
					{
						q[c + 1].push_back({ nx, ny });
					}
				}
			}
		}
	}
}


int main() {

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}
	BFS(0, 0, 0, M, N);
	cout << ans << "\n";

}