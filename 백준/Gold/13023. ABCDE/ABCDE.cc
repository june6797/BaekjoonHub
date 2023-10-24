#include <iostream>
#include <vector>
using namespace std;

vector<int> v[2001];
int visited[2001];
int ans;
void DFS(int start, int check) {
	if (check == 4)
	{
		ans = 1;
		return;
	}
	visited[start] = 1;
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visited[v[start][i]] == 0)
		{
			DFS(v[start][i], check + 1);
		}
	}
	
	visited[start] = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		if (v[i].size() > 0)
		{
			DFS(i, 0);
		}
	}
	cout << ans;
}