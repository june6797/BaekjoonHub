#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ti[10001];
int dp[10001];
vector<int> v[10001];
queue<int> q;
int have[10001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> ti[i];
		int M;
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			int num;
			cin >> num;
			v[num].push_back(i);
			have[i] = M;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (have[i] == 0)
		{
			dp[i] = ti[i];
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < v[t].size(); i++)
		{
			dp[v[t][i]] = max(dp[v[t][i]], dp[t] + ti[v[t][i]]);
			have[v[t][i]] -= 1;
			if (have[v[t][i]] == 0)
			{
				q.push(v[t][i]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;
}