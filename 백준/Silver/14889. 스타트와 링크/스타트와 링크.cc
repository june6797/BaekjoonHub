#include <iostream>
using namespace std;

int ability[21][21];
bool team[21];
int ans = 1234567890;
void DFS(int cnt, int s, int M, int N) {
	if (cnt == M)
	{
		int team1 = 0, team2 = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				if (team[i] == true)
				{
					if (team[j] == true)
					{
						team1 += ability[i][j] + ability[j][i];
					}
				}
				else
				{
					if (team[j] == false)
					{
						team2 += ability[i][j] + ability[j][i];
					}
				}
			}
		}
		int minus = abs(team1 - team2);
		ans = min(ans, minus);
		return;
	}
	if (s + M - cnt > N)
	{
		return;
	}
	for (int i = s + 1; i <= N; i++)
	{
		team[i] = 1;
		DFS(cnt + 1, i, M, N);
		team[i] = 0;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> ability[i][j];
		}
	}
	DFS(0, 0, N / 2, N);
	cout << ans;
}