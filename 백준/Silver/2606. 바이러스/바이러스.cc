#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

vector <int> adj[101];
queue <int> q;
int visit[101];

void DFS(int fisrt, int& ans) {
	visit[fisrt] = 1;
	q.push(fisrt);
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (int i = 0; i < adj[a].size(); i++)
		{
			if (visit[adj[a][i]] != 1)
			{
				visit[adj[a][i]] = 1;
				q.push(adj[a][i]);
				ans++;
			}
		}
	}
}


int main() {

	int cnum, adjnum, a, b;
	int ans = 0;
	cin >> cnum >> adjnum;
	for (int i = 0; i < adjnum; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	DFS(1, ans);
	cout << ans;
	
}
