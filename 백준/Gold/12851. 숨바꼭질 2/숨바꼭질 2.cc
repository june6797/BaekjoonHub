#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visit[100001];
int s[100001];
int a[100001];
queue<pair<int, int>> q;
void BFS(int start, int K) {
	int ans = 0;
	visit[start] = 1;
	q.push({ start, 0 });
	while (!q.empty())
	{
		int lo = q.front().first;
		int ti = q.front().second;
		q.pop();
		if (lo == K && visit[lo] == 0)
		{
			ans++;
			a[lo] = ti;
		}
		else if (lo == K && a[lo] == ti)
		{
			ans++;
		}

		visit[lo] = 1;

		if (lo - 1 >= 0 && visit[lo - 1] == 0)
		{
			q.push({ lo - 1, ti + 1 });
		}
		if (lo + 1 <= 100000 && visit[lo + 1] == 0)
		{
			q.push({ lo + 1, ti + 1 });
		}
		if (lo * 2 <= 100000 && visit[lo * 2] == 0)
		{
			q.push({ lo * 2, ti + 1 });
		}
	}
	cout << a[K] << "\n" << ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	BFS(N, K);

}