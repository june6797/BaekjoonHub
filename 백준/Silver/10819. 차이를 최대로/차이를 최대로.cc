#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int arr[8];
int make[8];
bool visit[8];
int ans = 0;
void DFS(int cnt, int N) {
	if (cnt == N)
	{
		int temp = 0;
		for (int i = 0; i < N - 1; i++)
		{
			temp += abs(make[i] - make[i + 1]);
		}
		ans = max(ans, temp);
	}
	for (int i = 0; i < N; i++)
	{
		if (visit[i] == false)
		{
			make[cnt] = arr[i];
			visit[i] = true;
			DFS(cnt + 1, N);
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	DFS(0, N);
	cout << ans;
}