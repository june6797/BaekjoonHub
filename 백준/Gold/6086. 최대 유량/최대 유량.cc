#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int c[260][260]; //용량
int f[260][260]; //flow
vector<int> edges[260];
int visited[260];
int result;
void maxFlow(int start, int end) {
	while (true)
	{
		memset(visited, -1, sizeof(visited));
		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < edges[x].size(); i++)
			{
				int n = edges[x][i];
				if (visited[n] == -1 && c[x][n] > f[x][n])
				{
					q.push(n);
					visited[n] = x;
					if (n == end)
					{
						break;
					}
				}
			}
		}
		if (visited[end] == -1)
		{
			break;
		}
		int flow = INF;
		for (int i = end; i != start; i = visited[i])
		{
			flow = min(flow, c[visited[i]][i] - f[visited[i]][i]);
		}
		for (int i = end; i != start; i = visited[i])
		{
			f[visited[i]][i] += flow;
			f[i][visited[i]] -= flow;
		}
		result += flow;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b;
		int cost;
		cin >> a >> b >> cost;
		edges[a - 'A'].push_back(b - 'A');
		edges[b - 'A'].push_back(a - 'A');
		c[a - 'A'][b - 'A'] += cost;
		c[b - 'A'][a - 'A'] += cost;
	}
	maxFlow(0, 25);
	cout << result;
}