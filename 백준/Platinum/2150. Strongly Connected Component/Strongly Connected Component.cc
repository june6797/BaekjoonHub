#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> v[10001];
int visit[10001];

vector<int> rv[10001];
int rvisit[10001];

stack<int> s;
vector<vector<int>> scc(10001);

bool cmp(vector<int> x, vector<int> y) {
	return x[0] < y[0];
}

void DFS(int start) {
	visit[start] = 1;
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visit[v[start][i]] == 0)
		{
			DFS(v[start][i]);
		}
	}
	s.push(start);
}
void rDFS(int start, int cnt) {
	rvisit[start] = 1;
	scc[cnt].push_back(start);
	for (int i = 0; i < rv[start].size(); i++)
	{
		if (rvisit[rv[start][i]] == 0)
		{
			rDFS(rv[start][i], cnt);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int V, E, cnt = 0;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		rv[b].push_back(a);
	}
	for (int i = 1; i <= V; i++)
	{
		if (visit[i] == 0)
		{
			DFS(i);
		}
	}
	while (!s.empty())
	{
		int t = s.top();
		s.pop();
		if (rvisit[t] == 0)
		{
			rDFS(t, cnt);
			cnt++;
		}
	}

	for (int i = 0; i <= cnt; i++)
	{
		sort(scc[i].begin(), scc[i].end());
	}
	scc.resize(cnt);
	sort(scc.begin(), scc.end(), cmp);
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < scc[i].size(); j++)
		{
			cout << scc[i][j] << " ";
		}
		cout << -1 << "\n";
	}
}