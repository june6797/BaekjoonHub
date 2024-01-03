#include <iostream>
using namespace std;

int N;
int ans = 1234567890;
int cost[10][10];
int order[10];
bool visit[10];
void DFS(int cnt, int level, int sum) {
	if (cnt == level)
	{
		if (cost[order[cnt - 1]][0] != 0)
		{
			ans = min(ans, sum + cost[order[cnt - 1]][0]);
		}
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visit[i] == 0 && cost[order[cnt - 1]][i] != 0)
		{
			visit[i] = 1;
			order[cnt] = i;
			DFS(cnt + 1, level, sum + cost[order[cnt - 1]][i]);
			visit[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> cost[i][j];
		}
	}
	visit[0] = 1;
	order[0] = 0;
	DFS(1, N, 0);
	if (ans == 1234567890)
	{
		cout << 0;
	}
	else
	{
		cout << ans;
	}
}