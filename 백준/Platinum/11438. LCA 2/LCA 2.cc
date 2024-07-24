#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

int n, m;
vector<int> edges[100001];
int parent[20][100001];
int depth[100001];
bool visited[100001];
void BFS(int start) {
	visited[start] = 1;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < edges[t].size(); i++)
		{
			int next = edges[t][i];
			if (!visited[next])
			{
				visited[next] = 1;
				parent[0][next] = t;
				depth[next] = depth[t] + 1;
				q.push(next);
			}
		}
	}
}

void LCA(int a, int b, int kmax) {
	if (depth[a] < depth[b])
	{
		swap(a, b);
	}
	for (int i = kmax; i >= 0; i--)
	{
		if (pow(2, i) <= depth[a] - depth[b])
		{
			if (depth[b] <= depth[parent[i][a]])
			{
				a = parent[i][a];
			}
		}
	}
	for (int i = kmax; i >= 0 && a != b; i--)
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
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	BFS(1);
	int kmax = log2(n) + 1;
	for (int i = 1; i <= kmax; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		LCA(a, b, kmax);
	}
}