#include <iostream>
#include <queue>
using namespace std;

int visit[100001];
int ans[100001];
int moves[2] = { -1, 1 };
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void BFS(int N, int K) {
	visit[N] = 1;
	q.push({ 0, N });
	while (!q.empty())
	{
		int p = q.top().first;
		int t = q.top().second;
		q.pop();
		if (t == K)
		{
			break;
		}
		if (t * 2 <= 100000 && visit[t * 2] == 0)
		{
			q.push({ p, t * 2 });
			visit[t * 2] = 1;
			ans[t * 2] = ans[t];
		}
		for (int i = 0; i < 2; i++)
		{
			int nmove = t + moves[i];
			if (nmove >= 0 && nmove <= 100000 && visit[nmove] == 0)
			{
				q.push({ p + 1, nmove });
				visit[nmove] = 1;
				ans[nmove] = ans[t] + 1;
			}
		}
	}
	cout << ans[K];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	BFS(N, K);
}