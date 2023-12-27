#include <iostream>
#include <queue>
using namespace std;

int visit[1001][1001];
queue<pair<int, int>> q;
int BFS(int start, int s) {
	visit[start][0] = 1;
	q.push({ start, 0 });
	while (!q.empty())
	{
		int top = q.front().first;
		int save = q.front().second;
		q.pop();
		if (top == s)
		{
			return visit[top][save] - 1;
		}
		if (top - 1 > 0 && visit[top - 1][save] == 0)
		{
			q.push({ top - 1, save });
			visit[top - 1][save] = visit[top][save] + 1;
		}
		if (top + save <= 1000 && visit[top + save][save] == 0)
		{
			q.push({ top + save, save });
			visit[top + save][save] = visit[top][save] + 1;
		}
		if (visit[top][top] == 0)
		{
			q.push({ top, top });
			visit[top][top] = visit[top][save] + 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s;
	cin >> s;
	cout << BFS(1, s);
}