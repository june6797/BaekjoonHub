#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

int n, m;
vector<int> v[501];
bool visit[501];
int ans;
void BFS(int start) {
	visit[start] = 1;
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	while (!q.empty())
	{
		int tnode = q.front().first;
		int dep = q.front().second;
		q.pop();
		for (int i = 0; i < v[tnode].size(); i++)
		{
			if (!visit[v[tnode][i]] && dep <= 1)
			{
				visit[v[tnode][i]] = 1;
				ans++;
				q.push({ v[tnode][i], dep + 1 });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	BFS(1);
	cout << ans;
}
