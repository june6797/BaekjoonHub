#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
vector<pair<int, int>> v[50];
long long int ans[50];
long long int money[50];
void BF(int N) {
	for (int t = 1; t < N; t++)
	{
		for (int i = 0; i <= N - 1; i++)
		{
			int start = i;
			for (int j = 0; j < v[start].size(); j++)
			{
				int end = v[start][j].first;
				int cost = v[start][j].second;
				if (ans[start] != LONG_MIN &&
					ans[start] - cost + money[end] > ans[end])
				{
					ans[end] = ans[start] - cost + money[end];
				}
			}
		}
	}

	for (int t = 1; t <= N; t++)
	{
		for (int i = 0; i <= N - 1; i++)
		{
			int start = i;
			for (int j = 0; j < v[start].size(); j++)
			{
				int end = v[start][j].first;
				int cost = v[start][j].second;

				if (ans[start] == LONG_MAX) {
					ans[end] = LONG_MAX;
				}
				else if (ans[start] != LONG_MIN &&
					ans[start] - cost + money[end] > ans[end])
				{
					ans[end] = LONG_MAX;
				}
			}
		}
	}
}
int main() {

	int N, start, end, M;
	cin >> N >> start >> end >> M;

	for (int i = 0; i < 50; i++)
	{
		ans[i] = LONG_MIN;
	}

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({ B, C });
	}
	for (int i = 0; i < N; i++)
	{
		int cost;
		cin >> cost;
		money[i] = cost;
	}
	ans[start] = money[start];

	BF(N);

	if (ans[end] == LONG_MAX)
	{
		cout << "Gee";
	}
	else if (ans[end] == LONG_MIN)
	{
		cout << "gg";
	}
	else
	{
		cout << ans[end];
	}
}