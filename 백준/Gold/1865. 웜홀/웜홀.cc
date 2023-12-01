#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int, int>> v[501];
int ans[501];

bool BF(int N) {
	for (int t = 1; t < N; t++)
	{
		for (int i = 1; i <= N; i++)
		{
			int start = i;
			for (size_t j = 0; j < v[i].size(); j++)
			{
				int end = v[start][j].first;
				int cost = v[start][j].second;
				if (ans[start] + cost < ans[end])
				{
					ans[end] = ans[start] + cost;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int start = i;
		for (size_t j = 0; j < v[i].size(); j++)
		{
			int end = v[start][j].first;
			int cost = v[start][j].second;
			if (ans[start] + cost < ans[end])
			{
				return true;
			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, M, W;
		cin >> N >> M >> W;

		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b, c });
			v[b].push_back({ a, c });
		}
		for (int i = 0; i < W; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b, -c });
		}
		if (BF(N))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
		for (int i = 1; i <= N; i++)
		{
			ans[i] = 0;
			v[i].clear();
		}
	}
}