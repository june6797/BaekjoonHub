#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

vector<pair<int, int>> v;
vector<int> edges[100001];
ll ans;
int arr[100001];
int parent[100001];
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int findparent(int a) {
	if (parent[a] < 0)
	{
		return a;
	}
	return parent[a] = findparent(parent[a]);
}
void unionfind(int a, int b) {
	a = findparent(a);
	b = findparent(b);
	if (a == b)
	{
		return;
	}
	parent[b] += parent[a];
	parent[a] = b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = -1;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		v.push_back({ arr[i], i });
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	sort(v.begin(), v.end(), compare);
	ans = v[0].first;
	for (int i = 0; i < v.size(); i++)
	{
		int tempnode = v[i].second;
		for (int j = 0; j < edges[tempnode].size(); j++)
		{
			if (arr[edges[tempnode][j]] >= arr[tempnode])
			{
				unionfind(edges[tempnode][j], tempnode);
				ll k = -1;
				ans = max(ans, k * arr[tempnode] * parent[findparent(tempnode)]);
			}
		}
	}
	cout << ans;

}
