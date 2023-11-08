#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
int cost[501];
int arr[501];
int ans[501];
vector<int> v[501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
		int a;
		cin >> a;
		while (a != -1)
		{
			v[a].push_back(i);
			arr[i]++;
			cin >> a;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int a = q.front();

		for (int i = 0; i < v[a].size(); i++)
		{
			arr[v[a][i]]--;
			ans[v[a][i]] = max(ans[a] + cost[a], ans[v[a][i]]);
			if (arr[v[a][i]] == 0)
			{
				q.push(v[a][i]);
			}
		}
		q.pop();
	}
	for (int i = 1; i <= N; i++)
	{
		cout << ans[i] + cost[i] << "\n";
	}
}