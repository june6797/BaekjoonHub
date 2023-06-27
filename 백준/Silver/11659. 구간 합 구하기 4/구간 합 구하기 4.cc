#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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
		cout << S[j] - S[i - 1] << "\n";
	}
	
}