#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[1001];
vector<int> ans;
int g[1001];
int temp[1001];
queue<int> q;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, cnt = 0;
	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> temp[j];
		}
		for (int j = 1; j < num; j++)
		{
			v[temp[j - 1]].push_back(temp[j]);
			g[temp[j]]++;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (g[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		ans.push_back(t);
		for (int i = 0; i < v[t].size(); i++)
		{
			g[v[t][i]]--;
			if (g[v[t][i]] == 0)
			{
				q.push(v[t][i]);
			}
		}
	}
	if (ans.size() == N)
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << "\n";
		}
	}
	else
	{
		cout << "0\n";
	}
}