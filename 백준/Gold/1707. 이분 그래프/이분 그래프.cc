#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[20001];
int ans[20001];
bool flag = false;

void DFS(int start, int check) {
	ans[start] = check;

	for (int i = 0; i < v[start].size(); i++)
	{
		if (ans[v[start][i]] == 0) {
			if (check == 1)
			{
				DFS(v[start][i], 2);
			}
			else
			{
				DFS(v[start][i], 1);
			}
		}
		else if (ans[v[start][i]] == check)
		{
			flag = true;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int V, E;
		cin >> V >> E;
		for (int j = 0; j < E; j++)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int j = 1; j <= V; j++)
		{
			if (ans[j] == 0)
			{
				DFS(j, 1);
			}
		}
		if (flag) {
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}

		for (int j = 1; j <= V; j++)
		{
			v[j].clear();
			ans[j] = 0;
		}
		flag = false;
	}
}