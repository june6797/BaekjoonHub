#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[50001];
int visit[50001];
int arr[2][50001];
queue<int> q;
void BFS(int start) {
	visit[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < v[t].size(); i++)
		{
			if (visit[v[t][i]] == 0)
			{
				visit[v[t][i]] = 1;
				arr[0][v[t][i]] = t;
				arr[1][v[t][i]] = arr[1][t] + 1;
				q.push(v[t][i]);
			}
		}
	}
}

void LCA(int a, int b) {
	if (arr[1][a] < arr[1][b])
	{
		int temp = a;
		a = b;
		b = temp;
	}

	while (arr[1][a] != arr[1][b])
	{
		a = arr[0][a];
	}
	while (a != b)
	{
		a = arr[0][a];
		b = arr[0][b];
	}
	cout << a << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	BFS(1);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		LCA(a, b);
	}
}