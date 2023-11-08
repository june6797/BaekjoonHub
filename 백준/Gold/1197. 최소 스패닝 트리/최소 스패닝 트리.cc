#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
	greater<pair<int, pair<int, int>>>> q;

int arr[10001];
int find(int a) {
	if (a == arr[a])
	{
		return a;
	}
	else
	{
		return arr[a] = find(arr[a]);
	}
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b)
	{
		arr[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10001; i++)
	{
		arr[i] = i;
	}
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		q.push({ c, { a , b } });
	}
	int ans = 0;
	while (!q.empty())
	{
		int cost = q.top().first;
		int f = q.top().second.first;
		int s = q.top().second.second;
		if (find(f) != find(s))
		{
			uni(f, s);
			ans += cost;
		}
		q.pop();
	}
	cout << ans;
}