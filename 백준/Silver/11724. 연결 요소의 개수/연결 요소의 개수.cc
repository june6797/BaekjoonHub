#include <iostream>
#include <vector>
using namespace std;

vector<int> a[1001];
int visit[1001];

void DFS(int start) {
	visit[start] = 1;
	for (int i = 0; i < a[start].size(); i++)
	{
		if (visit[a[start][i]] == 0)
		{
			DFS(a[start][i]);
		}
	}
}

int main() {
	int N, M, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 0)
		{
			DFS(i);
			ans++;
		}
	}
	cout << ans;
}