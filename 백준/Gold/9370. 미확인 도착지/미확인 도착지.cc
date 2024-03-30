#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int sarr[2001];
int garr[2001];
int harr[2001];
vector<pair<int, int>> v[2001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void Dij(int start, int arr[2001]) {
	arr[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int node = pq.top().second;
		int tcost = pq.top().first;
		pq.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int nnode = v[node][i].first;
			int ncost = tcost + v[node][i].second;
			if (arr[nnode] > ncost)
			{
				arr[nnode] = ncost;
				pq.push({ ncost, nnode });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, t;
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;
		int ghcost = 0;
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b, c });
			v[b].push_back({ a, c });
			if ((g == a && h == b) || (g == b && h == a))
			{
				ghcost = c;
			}

		}
		for (int i = 1; i <= n; i++)
		{
			sarr[i] = 987654321;
			garr[i] = 987654321;
			harr[i] = 987654321;
		}
		Dij(s, sarr);
		Dij(g, garr);
		Dij(h, harr);
		vector<int> ans;
		for (int i = 0; i < t; i++)
		{
			int d;
			cin >> d;
			if ((sarr[g] + ghcost + harr[d] == sarr[d]) ||
				(sarr[h] + ghcost + garr[d] == sarr[d]))
			{
				ans.push_back(d);
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
		for (int i = 1; i <= n; i++)
		{
			v[i].clear();
		}
	}
}