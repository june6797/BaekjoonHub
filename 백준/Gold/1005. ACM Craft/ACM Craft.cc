#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[1001];
int ans[1001];
int g[1001];
vector<int> v[1001];
queue<int> q;


int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, K;
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			g[y]++;
		}
		for (int i = 1; i <= N; i++)
		{
			if (g[i] == 0)
			{
				q.push(i);
			}

			ans[i] += arr[i];
		}

		while (!q.empty())
		{
			int t = q.front();
			q.pop();
			for (int i = 0; i < v[t].size(); i++)
			{
				ans[v[t][i]] = max(ans[v[t][i]], ans[t] + arr[v[t][i]]);
				g[v[t][i]]--;
				if (g[v[t][i]] == 0)
				{
					q.push(v[t][i]);
				}
			}
		}
		int W;
		cin >> W;
		cout << ans[W] << "\n";
		for (int i = 1; i <= N; i++)
		{
			ans[i] = 0;
			v[i].clear();
			arr[i] = 0;
			g[i] = 0;
		}
	}
}