#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[100001];
queue<int> q;
int visited[100001];
int ans[100001];
void BFS(int start) {
	q.push(start);
	visited[start] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < adj[x].size(); i++)
		{
			if ( visited[adj[x][i]] == 0)
			{
				q.push(adj[x][i]);
				visited[adj[x][i]] = 1;
				ans[adj[x][i]] = x;
			}
		}

	}
}

int main() {
	int N, a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	BFS(1);
	for (int i = 2; i <= N; i++)
	{
		cout << ans[i] << "\n";
	}
}