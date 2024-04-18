#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1000001];
int dp[1000001][2];
bool visit[1000001];

void DFS(int start) {
	visit[start] = 1;
	dp[start][0] = 1;
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visit[v[start][i]] == 0)
		{
			DFS(v[start][i]);
			dp[start][0] += min(dp[v[start][i]][0], dp[v[start][i]][1]);
			dp[start][1] += dp[v[start][i]][0];
		}
	}

}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	DFS(1);
	cout << min(dp[1][0], dp[1][1]);
}