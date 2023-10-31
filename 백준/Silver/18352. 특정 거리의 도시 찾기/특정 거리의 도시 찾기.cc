#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visit[300001];
int ans[300001];
vector<int> v[300001];
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
				ans[v[t][i]] = ans[t] + 1;
				q.push(v[t][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	BFS(X);
	int r = 0;
	for (int i = 1; i <= N; i++)
	{
		if (ans[i] == K)
		{
			cout << i << "\n";
			r++;
		}
	}
	if (r == 0)
	{
		cout << "-1";
	}
}