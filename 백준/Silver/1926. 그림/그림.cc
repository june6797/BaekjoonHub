#include <iostream>
using namespace std;

int n, m;
int arr[500][500];
int ans = 0;
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
void DFS(int x, int y) {
	arr[x][y] = 0;
	ans++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + x_move[i];
		int ny = y + y_move[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
			arr[nx][ny] == 1)
		{
			DFS(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				ans = 0;
				DFS(i, j);
				cnt++;
				k = max(k, ans);
			}
		}
	}
	cout << cnt << "\n" << k;
}