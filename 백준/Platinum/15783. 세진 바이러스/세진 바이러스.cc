#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> v[100001];
int visit[100001];

vector<int> rv[100001];
int rvisit[100001];

stack<int> s;

int scc[100001];
int indegree[100001];
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
	scc[start] = cnt;
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

	int V, E, cnt = 0, ans = 0;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		rv[b].push_back(a);
	}
	for (int i = 0; i < V; i++)
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
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (scc[i] != scc[v[i][j]])
			{
				indegree[scc[v[i][j]]]++;
			}
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		if (indegree[i] == 0)
		{
			ans++;
		}
	}
	cout << ans;
	for (int i = 0; i <= V; i++)
	{
		v[i].clear();
		rv[i].clear();
		visit[i] = 0;
		rvisit[i] = 0;
		scc[i] = 0;
		indegree[i] = 0;
	}

}