#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int n, k;
pair<int, int> arr[104];
vector<int> v[104];
bool visit[104];
bool BFS(int x) {
	queue<int> q;
	q.push(x);
	visit[x] = 1;
	while (!q.empty())
	{
		int tx = q.front();
		q.pop();
		if (tx == n + 1)
		{
			return true;
		}
		for (int i = 0; i < v[tx].size(); i++)
		{
			if (!visit[v[tx][i]])
			{
				visit[v[tx][i]] = 1;
				q.push(v[tx][i]);
			}
		}
	}
	return false;
}

bool check(pair<int, int> x, pair<int, int> y) {
	int a = abs(x.first - y.first);
	int b = abs(x.second - y.second);
	return a + b <= 1000;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n + 2; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[i] = { x, y };
		}
		for (int i = 0; i < n + 1; i++)
		{
			for (int j = i + 1; j < n + 2; j++)
			{
				if (check(arr[i], arr[j]))
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		if (BFS(0)) {
			cout << "happy\n";
		}
		else
		{
			cout << "sad\n";
		}
		for (int i = 0; i < 103; i++)
		{
			v[i].clear();
			visit[i] = 0;
		}

	}

}