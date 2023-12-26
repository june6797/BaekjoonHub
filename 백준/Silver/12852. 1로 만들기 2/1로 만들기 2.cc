#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dp[1000001];
int visit[1000001];
vector<int> v;
queue<pair<int, int>> q;
void BFS(int start, int N) {
	if (visit[start] == 0)
	{
		visit[start] == 0;
	}
	q.push({ start, 0 });
	while (!q.empty())
	{
		int t = q.front().first;
		int g = q.front().second;
		q.pop();
		if (t == N)
		{
			break;
		}
		if (t * 3 <= 1000000 && visit[t * 3] == 0)
		{
			q.push({ t * 3, g + 1 });
			dp[t * 3] = t;
			visit[t * 3] = 1;
		}
		if (t * 2 <= 1000000 && visit[t * 2] == 0)
		{
			q.push({ t * 2, g + 1 });
			dp[t * 2] = t;
			visit[t * 2] = 1;
		}
		if (t + 1 <= 1000000 && visit[t + 1] == 0)
		{
			q.push({ t + 1, g + 1 });
			dp[t + 1] = t;
			visit[t + 1] = 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	BFS(1, N);
	int ans = 0;
	while (dp[N] != 0)
	{
		ans++;
		v.push_back(N);
		N = dp[N];
	}
	cout << ans << "\n";
	for (int i = 0; i < ans; i++)
	{
		cout << v[i] << " ";
	}
	cout << 1;
}