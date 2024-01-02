#include <iostream>
using namespace std;

int N, S, ans;
int arr[21];
bool flag[21];
void DFS(int cnt, int start, int M, int s, int sum) {
	if (cnt == M)
	{
		if (s == S)
		{
			ans++;
		}
		/*if (sum - s == S)
		{
			ans++;
		}*/
		return;
	}

	for (int i = start + 1; i <= N; i++)
	{
		DFS(cnt + 1, i, M, s + arr[i], sum);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int sum = 0;
	cin >> N >> S;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 1; i <= N; i++)
	{
		DFS(0, 0, i, 0, sum);
	}
	cout << ans;
}