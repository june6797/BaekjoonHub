#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[1001];
queue<int> q;
int visited[1001];
int ans;
void DFS(int start) {
	visited[start] = 1;
	cout << start << " ";
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visited[v[start][i]] == 0)
		{
			DFS(v[start][i]);
		}
	}
}
void BFS(int start) {
	visited[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int a = q.front();
		cout << a << " ";
		q.pop();
		for (int i = 0; i < v[a].size(); i++)
		{
			if (visited[v[a][i]] == 0)
			{
				q.push(v[a][i]);
				visited[v[a][i]] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, V;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	DFS(V);
	cout << "\n";
	for (int i = 1; i <= N; i++)
	{
		visited[i] = 0;
	}
	BFS(V);
}