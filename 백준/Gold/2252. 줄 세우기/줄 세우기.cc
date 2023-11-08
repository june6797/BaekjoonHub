#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[32001];
vector<int> v[32001];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
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
		int ans = q.front();
		cout << ans << " ";
		for (int i = 0; i < v[ans].size(); i++)
		{
			arr[v[ans][i]]--;
			if (arr[v[ans][i]] == 0)
			{
				q.push(v[ans][i]);
			}
		}
		q.pop();
	}
}