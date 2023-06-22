#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector <int> adj[1001];
queue <int> q;
int visit[1001];

void BFS(int start) {
	q.push(start);
	visit[start] = 1;

	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (int i = 0; i < adj[a].size(); i++)
		{
			if (visit[adj[a][i]] == 0)
			{
				q.push(adj[a][i]);
				visit[adj[a][i]] = 1;
			}
		}

	}
}



int main() {
	int N, M, a, b, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (visit[i] == 0)
		{
			BFS(i);
			ans++;
		}
	}
	cout << ans;
}
