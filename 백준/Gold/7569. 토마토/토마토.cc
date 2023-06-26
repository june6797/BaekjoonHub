#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int arr[101][101][101];
int dist[101][101][101];
int M, N, H;
queue <tuple<int, int, int>> q;
vector <tuple<int, int, int>> v;
int x_move[6] = { -1, 1, 0, 0 , 0, 0 };
int y_move[6] = { 0, 0, -1, 1, 0, 0 };
int z_move[6] = { 0, 0, 0, 0, -1, 1 };

void BFS(int& ans) {

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int x_next = x + x_move[i];
			int y_next = y + y_move[i];
			int z_next = z + z_move[i];
			if (x_next >= 0 && x_next < H && y_next >= 0 && y_next < N
				&& z_next >= 0 && z_next < M && arr[x_next][y_next][z_next] == 0)
			{
				q.push({ x_next, y_next, z_next });
				dist[x_next][y_next][z_next] = dist[x][y][z] + 1;
				arr[x_next][y_next][z_next] = 1;
			}
		}

	}
}

int main() {
	int n, checkall = 0, ans = 0;
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> n;
				if (n == 0)
				{
					checkall = 1;
				}
				else if (n == 1)
				{
					q.push({ i, j, k });
				}
				arr[i][j][k] = n;
			}
		}
	}

	if (checkall == 0)
	{
		cout << "0\n";
		return 0;
	}
	else
	{

		BFS(ans);

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					if (ans < dist[i][j][k])
					{
						ans = dist[i][j][k];
					}

					if (arr[i][j][k] == 0)
					{
						cout << "-1\n";
						return 0;
					}
				}
			}
		}
	}
	cout << ans;
}