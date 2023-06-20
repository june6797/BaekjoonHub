#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int BFSv[1001] = { 0 };
int DFSv[1001] = { 0 };
vector<int> adj[1001];
queue<int> Q;

void BFS(int start) {
	BFSv[start] = 1;
	Q.push(start);
	while (!Q.empty())
	{
		int x = Q.front();
		cout << x << " ";
		Q.pop();
		for (int i = 0; i < adj[x].size(); i++)
		{
			int next = adj[x][i];
			if (BFSv[next] != 1)
			{
				BFSv[next] = 1;
				Q.push(next);
			}
		}
	}
}

void DFS(int start) {
	DFSv[start] = 1;
	Q.push(start);
	int x = Q.front();
	cout << x << " ";
	Q.pop();
	for (int i = 0; i < adj[x].size(); i++)
	{
		int next = adj[x][i];
		if (DFSv[next] != 1)
		{
			DFS(next);
		}
	}

}


int main() {
	int N, M, V, a, b;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}

	DFS(V);
	cout << "\n";
	BFS(V);
}