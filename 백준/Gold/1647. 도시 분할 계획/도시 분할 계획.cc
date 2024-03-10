#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v[100001];
bool visit[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int prim(int N) {
	int ans = 0;
	int maxcost = 0;
	pq.push({ 0, 1 });
	for (int i = 0; i < N; i++)
	{
		while (!pq.empty() && visit[pq.top().second])
		{
			pq.pop();
		}
		int nextnode = pq.top().second;
		int cost = pq.top().first;
		visit[nextnode] = 1;
		maxcost = max(maxcost, cost);
		ans += cost;
		for (int i = 0; i < v[nextnode].size(); i++)
		{
			pq.push({ v[nextnode][i].second, v[nextnode][i].first });
		}
	}
	return ans - maxcost;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	cout << prim(N);
}