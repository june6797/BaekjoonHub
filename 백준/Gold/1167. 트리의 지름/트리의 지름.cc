#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v[100001];
queue<int> q;

int visited[100001];
int ans[100001];

void BFS(int start) {
	visited[start] = 1;
	ans[start] = 0;
	q.push(start);
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (int i = 0; i < v[a].size(); i++)
		{
			if (visited[v[a][i].first] == 0)
			{
				q.push(v[a][i].first);
				visited[v[a][i].first] = 1;
				ans[v[a][i].first] = ans[a] + v[a][i].second;
			}
		}
	}
}

int main() {
	int V;
	cin >> V;
	for (int i = 0; i < V; i++)
	{
		int num, a, b;
		cin >> num;
		while (true)
		{
			cin >> a;
			if (a == -1)
			{
				break;
			}
			cin >> b;
			v[num].push_back({ a, b });
		}
	}
	BFS(1);
	int m = 0;
	int idx = -1;
	for (int i = 1; i <= V; i++)
	{
		if (ans[i] > m)
		{
			idx = i;
		}
		m = max(m, ans[i]);
		visited[i] = 0;
		ans[i] = 0;
	}
	BFS(idx);
	m = 0;
	for (int i = 1; i <= V; i++)
	{
		m = max(m, ans[i]);
	}
	cout << m;
}