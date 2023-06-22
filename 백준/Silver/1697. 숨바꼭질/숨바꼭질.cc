#include <iostream>
#include <queue>
using namespace std;

int visit[100001];
int ans[100001];
queue<int> q;

void DFS(int N, int K) {
	q.push(N);
	visit[N] = 1;
	while (q.front() != K)
	{
		int a = q.front();
		q.pop();

		if (a * 2 < 100001 && visit[a * 2] != 1)
		{
			visit[a * 2] = 1;
			q.push(a * 2);
			ans[a * 2] = ans[a] + 1;

		}
		if (a + 1 < 100001 && visit[a + 1] != 1)
		{
			visit[a + 1] = 1;
			q.push(a + 1);
			ans[a + 1] = ans[a] + 1;
		}
		if (a - 1 > -1 && visit[a - 1] != 1)
		{
			visit[a - 1] = 1;
			q.push(a - 1);
			ans[a - 1] = ans[a] + 1;
		}
	}
}



int main() {
	int N, K;
	cin >> N >> K;
	DFS(N, K);

	cout << ans[K];
}
