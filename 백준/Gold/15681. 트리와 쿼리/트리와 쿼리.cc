#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
int dp[100001];
int visit[100001];
void DFS(int start) {
	visit[start] = 1;
	bool flag = true;
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visit[v[start][i]] == 0)
		{
			flag = false;
			DFS(v[start][i]);
			dp[start] += dp[v[start][i]];
			visit[v[start][i]] = 1;
		}
	}
	dp[start]++;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, R, Q;
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	DFS(R);
	for (int i = 0; i < Q; i++)
	{
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}
}