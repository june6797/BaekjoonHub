#include <iostream>
using namespace std;

int make[8];
bool visit[8];
void DFS(int cnt, int N) {
	if (cnt == N)
	{
		int temp = 0;
		for (int i = 0; i < N; i++)
		{
			cout << make[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == false)
		{
			make[cnt] = i;
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
	DFS(0, N);
}