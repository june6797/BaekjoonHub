#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visit[50];
int parent[50];
queue<int> q;
vector<int>v[50];
int ans;
void BFS(int start) {
	if (v[start].size() == 0)
	{
		ans++;
		return;
	}
	visit[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (v[t].size() == 1 && start != t)
		{
			ans++;
		}
		for (int i = 0; i < v[t].size(); i++)
		{
			if (visit[v[t][i]] == 0)
			{
				visit[v[t][i]] = 1;
				q.push(v[t][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int N, num, start;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		parent[i] = num;
		if (num == -1)
		{
			start = i;
		}
		else
		{
			v[i].push_back(num);
			v[num].push_back(i);
		}
	}
	cin >> num;
	int p = parent[num];
	if (p == -1)
	{
		cout << 0;
	}
	else
	{
		int cnt = 0;
		for (int i = 0; i < v[p].size(); i++)
		{
			if (v[p][i] == num)
			{
				v[p].erase(v[p].begin() + i);
			}
		}
		BFS(start);

		cout << ans;
	}

}