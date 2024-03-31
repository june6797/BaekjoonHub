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

vector<pair<int, int>> v[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int arr[100001], n;
void Dij(int start) {
	arr[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int newnode = v[node][i].first;
			int newcost = v[node][i].second + cost;
			if (arr[newnode] > newcost)
			{
				arr[newnode] = newcost;
				pq.push({ newcost, newnode });
			}
		}
	}
	int ans = 0, tt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] != 987654321)
		{
			ans++;
			if (tt < arr[i])
			{
				tt = arr[i];
			}
		}
	}
	cout << ans << " " << tt << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int d, s;
		cin >> n >> d >> s;
		for (int i = 1; i <= n; i++)
		{
			arr[i] = 987654321;
		}
		for (int i = 0; i < d; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			v[b].push_back({ a, c });
		}
		Dij(s);
		for (int i = 1; i <= n; i++)
		{
			v[i].clear();
		}
	}
}
