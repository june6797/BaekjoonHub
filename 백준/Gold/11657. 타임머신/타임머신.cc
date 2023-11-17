#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
vector<pair<int, int>> v[501];
long long int ans[501];
bool BF(int N) {
	for (int t = 1; t < N; t++)
	{
		for (int i = 1; i <= N; i++)
		{
			int start = i;
			for (int j = 0; j < v[start].size(); j++)
			{
				int end = v[start][j].first;
				int cost = v[start][j].second;
				if (ans[start] != LONG_MAX &&
					ans[start] + cost < ans[end])
				{
					ans[end] = ans[start] + cost;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int start = i;
		for (int j = 0; j < v[start].size(); j++)
		{
			int end = v[start][j].first;
			int cost = v[start][j].second;
			if (ans[start] != LONG_MAX &&
				ans[start] + cost < ans[end])
			{
				return true;
			}
		}
	}
	return false;
}
int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < 501; i++)
	{
		ans[i] = LONG_MAX;
	}

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({ B, C });
	}
	ans[1] = 0;
	if (BF(N)) {
		cout << "-1\n";
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (ans[i] == LONG_MAX)
			{
				cout << "-1\n";
			}
			else
			{
				cout << ans[i] << "\n";
			}
		}
	}
}
