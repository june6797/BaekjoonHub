#include <iostream>
#include <queue>
using namespace std;

int visit[1000001];
int ans[1000001];
queue<int> q;

void BFS(int start, int end, int u, int d, int f) {
	visit[start] = 1;
	ans[start] = 0;
	int go[2] = { u, -d };
	q.push(start);

	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		if (a == end)
		{
			cout << ans[a];
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			int c = a + go[i];
			if (c > 0 && c <= f
				&& visit[c] == 0)
			{
				q.push(c);
				visit[c] = 1;
				ans[c] = ans[a] + 1;
			}
		}
	}
	cout << "use the stairs";
}

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	BFS(s, g, u, d, f);
}
