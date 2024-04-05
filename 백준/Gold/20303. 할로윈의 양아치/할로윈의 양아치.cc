#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <map>
typedef long long int ll;
using namespace std;

int candy[30001];
vector<int> v[30001];
bool visit[30001];
queue<int> q;
vector<pair<int, int>> l;
int cache[3001][30001];
int dp[30001];
int n, m, k;
void BFS(int start) {
	visit[start] = 1;
	q.push(start);
	int sum = candy[start];
	int child = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < v[t].size(); i++)
		{
			if (visit[v[t][i]] == 0)
			{
				visit[v[t][i]] = 1;
				sum += candy[v[t][i]];
				q.push(v[t][i]);
				child++;
			}
		}
	}
	l.push_back({ sum, child });
}

int solve(int child, int capacity, int ss) {
	if (child == ss)
	{
		return 0;
	}
	int& ret = cache[capacity][child];
	if (ret != 0)
	{
		return ret;
	}
	ret = solve(child + 1, capacity, ss);
	if (l[child].second <= capacity)
	{
		ret = max(ret, solve(child + 1, capacity - l[child].second, ss) + l[child].first);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> candy[i];
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			BFS(i);
		}
	}
	int ss = l.size();
	//cout << solve(0, k - 1, ss);
	for (int i = 0; i < ss; i++)
	{
		for (int j = k - 1; j >= l[i].second; j--)
		{
			dp[j] = max(dp[j], dp[j - l[i].second] + l[i].first);
		}
	}
	cout << dp[k - 1];
}
