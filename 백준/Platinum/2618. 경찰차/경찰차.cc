#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001];
int e[2][1001];

int DFS(int x, int y, int N, int W) {
	if (x == W || y == W)
	{
		return 0;
	}
	if (dp[x][y])
	{
		return dp[x][y];
	}

	int next = max(x, y) + 1;
	int xdist = 0;
	int ydist = 0;
	if (x == 0)
	{
		xdist = abs(e[0][next] - 1) + abs(e[1][next] - 1);
	}
	else
	{
		xdist = abs(e[0][next] - e[0][x]) + abs(e[1][next] - e[1][x]);
	}

	if (y == 0)
	{
		ydist = abs(e[0][next] - N) + abs(e[1][next] - N);
	}
	else
	{
		ydist = abs(e[0][next] - e[0][y]) + abs(e[1][next] - e[1][y]);
	}
	dp[x][y] = min((DFS(next, y, N, W) + xdist), DFS(x, next, N, W) + ydist);
	return dp[x][y];
}

void findRoad(int x, int y, int N, int W) {
	if (x == W || y == W)
	{
		return;
	}

	int next = max(x, y) + 1;
	int xdist = 0;
	int ydist = 0;
	if (x == 0)
	{
		xdist = abs(e[0][next] - 1) + abs(e[1][next] - 1);
	}
	else
	{
		xdist = abs(e[0][next] - e[0][x]) + abs(e[1][next] - e[1][x]);
	}

	if (y == 0)
	{
		ydist = abs(e[0][next] - N) + abs(e[1][next] - N);
	}
	else
	{
		ydist = abs(e[0][next] - e[0][y]) + abs(e[1][next] - e[1][y]);
	}

	if (dp[next][y] + xdist < dp[x][next] + ydist)
	{
		cout << "1\n";
		findRoad(next, y, N, W);
	}
	else
	{
		cout << "2\n";
		findRoad(x, next, N, W);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, W;
	cin >> N >> W;
	for (int i = 1; i <= W; i++)
	{
		cin >> e[0][i] >> e[1][i];
	}
	cout << DFS(0, 0, N, W) << "\n";
	findRoad(0, 0, N, W);
}