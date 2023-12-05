#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> v[100001];
int visit[100001];
int depth[100001];
int parent[21][100001];
queue<int> q;
void BFS(int start) {
	visit[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < v[t].size(); i++)
		{
			if (visit[v[t][i]] == 0)
			{
				visit[v[t][i]] = 1;
				parent[0][v[t][i]] = t;
				depth[v[t][i]] = depth[t] + 1;
				q.push(v[t][i]);
			}
		}
	}
}

void LCA(int a, int b, int m) {
	if (depth[a] < depth[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i = m; i >= 0; i--)
	{
		if (pow(2, i) <= depth[a] - depth[b])
		{
			if (depth[b] <= depth[parent[i][a]])
			{
				a = parent[i][a];
			}
		}
	}
	for (int i = m; i >= 0 && a != b; i--)
	{
		if (parent[i][a] != parent[i][b])
		{
			a = parent[i][a];
			b = parent[i][b];
		}

	}
	if (a != b)
	{
		cout << parent[0][a] << "\n";
	}
	else
	{
		cout << a << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	BFS(1);
	int max = log2(N) + 1;
	for (int i = 1; i <= max; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		LCA(a, b, max);
	}
}