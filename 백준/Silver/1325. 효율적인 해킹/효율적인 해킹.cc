#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visit[10001];
int ans[10001];
vector<int> v[10001];
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
				ans[v[t][i]] += 1;
				q.push(v[t][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= N; i++)
	{
		BFS(i);
		for (int j = 1; j <= N; j++)
		{
			visit[j] = 0;
		}
	}
	int m = 0;
	for (int i = 1; i <= N; i++)
	{
		if (m < ans[i])
		{
			m = ans[i];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (m == ans[i])
		{
			cout << i << " ";
		}
	}


}