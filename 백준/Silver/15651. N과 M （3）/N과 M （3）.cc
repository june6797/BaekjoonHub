#include <iostream>
using namespace std;

int arr[9];
void DFS(int cnt, int N, int M) {
	if (cnt == M + 1)
	{
		for (int i = 1; i <= M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		arr[cnt] = i;
		DFS(cnt + 1, N, M);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	DFS(1, N, M);
}