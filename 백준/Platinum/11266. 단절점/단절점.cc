#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int v, e, cnt;
vector<int> ans;
vector<int> edges[10001];
int visited[10001];
bool cut[10001];
int dfs(int idx, bool check) {
	cnt++;
	visited[idx] = cnt;
	int ret = visited[idx];
	int child = 0;
	for (int i = 0; i < edges[idx].size(); i++)
	{
		int next = edges[idx][i];
		if (visited[next])
		{
			ret = min(ret, visited[next]);
			continue;
		}
		child++;
		int temp = dfs(next, false);
		if (!check && temp >= visited[idx])
		{
			cut[idx] = true;
		}
		ret = min(ret, temp);
	}
	if (check && child > 1)
	{
		cut[idx] = true;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 1; i <= v; i++)
	{
		if (!visited[i])
		{
			dfs(i, true);
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (cut[i])
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}