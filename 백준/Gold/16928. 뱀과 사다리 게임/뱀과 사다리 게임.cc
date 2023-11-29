#include <iostream>
#include <queue>
using namespace std;

int arr[101];
int visit[101];
int ans[101];
queue<int> q;

void BFS(int x) {
	visit[x] = 1;
	q.push(x);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (t == 100)
		{
			cout << ans[t];
			break;
		}
		for (int i = 1; i <= 6; i++)
		{
			int nx = t + i;
			if (nx <= 100 && visit[nx] == 0)
			{
				if (arr[nx] != 0)
				{
					nx = arr[nx];
				}
				if (visit[nx] == 0)
				{

					visit[nx] = 1;
					ans[nx] = ans[t] + 1;
					q.push(nx);
				}
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}
	BFS(1);
}