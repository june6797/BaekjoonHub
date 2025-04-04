#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

int n, m, k, ans = 987654321;
int person[11];
bool check[11];
bool connect[11][11];
bool visit[11];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool BFS(vector<int> v, bool k) {
	for (int i = 0; i < 11; i++)
	{
		visit[i] = 0;
	}
	queue<int> q;
	q.push(v[0]);
	visit[v[0]] = 1;
	int cnt = 1;
	while (!q.empty())
	{
		int tx = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (connect[tx][i] == 1 && check[i] == k
				&& !visit[i]) {
				visit[i] = 1;
				cnt++;
				q.push(i);
			}
		}
	}
	if (v.size() == cnt)
	{
		return true;
	}
	return false;
}

bool checkConnect() {
	vector<int> a;
	vector<int> b;
	for (int i = 1; i <= n; i++)
	{
		if (check[i]) {
			a.push_back(i);
		}
		else
		{
			b.push_back(i);
		}
	}
	if (a.empty() || b.empty()) {
		return false;
	}
	if (BFS(a, true) == false)
	{
		return false;
	}
	if (BFS(b, false) == false)
	{
		return false;
	}
	return true;
}

void cal() {
	int a = 0, b = 0, c = 0;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == true)
		{
			a += person[i];
		}
		else
		{
			b += person[i];
		}
	}
	c = abs(a - b);
	ans = min(ans, c);
}
void DFS(int idx, int dep) {
	if (dep >= 1) {
		if (checkConnect()) {
			cal();
		}
	}
	for (int i = idx; i <= n; i++)
	{

		check[i] = true;
		DFS(i + 1, dep + 1);
		check[i] = false;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> person[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			int b;
			cin >> b;
			connect[i][b] = 1;
			// connect[b][i] = 1;
		}
	}
	DFS(1, 0);
	if (ans == 987654321)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
}
