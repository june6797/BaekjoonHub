#include <iostream>

using namespace std;

int main() {

	int N, M, i, j;
	cin >> N >> M;
	int S[100001] = {};
	int ans[100001] = {};
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		S[i] = S[i - 1] + num;
	}
	for (int a = 0; a < M; a++)
	{
		cin >> i >> j;
		ans[a] =  S[j] - S[i - 1];
	}
	for (int i = 0; i < M; i++)
	{
		cout << ans[i] << "\n";
	}
}