#include <bits/stdc++.h>
#define mod 1000000007
#define INF 987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int v, e, cnt;
vector<pii> ans;
vector<int> edges[100001];
int visited[100001];
int dfs(int idx, int parent) {
	cnt++;
	visited[idx] = cnt;
	int ret = visited[idx];
	for (int i = 0; i < edges[idx].size(); i++)
	{
		int next = edges[idx][i];
		if (visited[next] == 0)
		{
			int temp = dfs(next, idx);
			if (temp > visited[idx])
			{
				if (idx > next)
				{
					ans.push_back({ next, idx });
				}
				else
				{
					ans.push_back({ idx, next });
				}
			}
			ret = min(ret, temp);
		}
		else
		{
			if (next != parent)
			{
				ret = min(ret, visited[next]);
			}
		}
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
			dfs(i, 0);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
}