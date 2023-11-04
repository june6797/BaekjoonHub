#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[101];
int visit[101];
int ans[101];
queue<int> q;

void BFS(int x, int y) {
	visit[x] = 1;
	ans[x] = 0;
	q.push(x);

	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		if (a == y)
		{
			cout << ans[a];
			return;
		}
		for (int i = 0; i < v[a].size(); i++)
		{
			int c = v[a][i];
			if (visit[c] == 0)
			{
				q.push(c);
				visit[c] = 1;
				ans[c] = ans[a] + 1;
			}
		}
	}
	cout << "-1";
}

int main() {
	int n, a, b, m, x, y;
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	BFS(a, b);
}
