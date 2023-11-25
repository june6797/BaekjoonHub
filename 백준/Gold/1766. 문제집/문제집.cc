#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int g[32001];
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int>> pq;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		g[y]++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (g[i] == 0)
		{
			pq.push(i);
		}
	}

	while (!pq.empty())
	{
		int t = pq.top();
		pq.pop();
		cout << t << " ";
		for (int i = 0; i < v[t].size(); i++)
		{
			g[v[t][i]]--;
			if (g[v[t][i]] == 0)
			{
				pq.push(v[t][i]);
			}
		}
	}
}