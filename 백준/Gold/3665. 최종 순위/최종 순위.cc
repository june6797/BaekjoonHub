#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[501][501];
int g[501];
int lastscore[501];
vector<int> ans;
queue<int> q;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, M;
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			cin >> lastscore[i];
		}
		for (int i = 1; i < N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				arr[lastscore[i]][lastscore[j]] = 1;
				g[lastscore[j]]++;
			}
		}
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			int x, y;
			cin >> x >> y;
			if (arr[x][y] == 1)
			{
				g[y]--;
				g[x]++;
			}
			else
			{
				g[y]++;
				g[x]--;
			}
			swap(arr[x][y], arr[y][x]);
		}
		for (int i = 1; i <= N; i++)
		{
			if (g[i] == 0)
			{
				q.push(i);
			}
		}

		while (!q.empty())
		{
			int t = q.front();
			ans.push_back(t);
			q.pop();

			for (int i = 1; i <= N; i++)
			{
				if (arr[t][i] == 1)
				{
					g[i]--;
					if (g[i] == 0)
					{
						q.push(i);
					}
				}
			}
		}

		if (ans.size() != N)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i] << " ";
			}
			cout << "\n";
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				arr[i][j] = 0;
			}
			g[i] = 0;
			lastscore[i] = 0;
		}

		ans.clear();
	}

}