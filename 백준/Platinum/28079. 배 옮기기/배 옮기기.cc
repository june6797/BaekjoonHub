#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <regex>
typedef long long int ll;
using namespace std;

vector<int> v;
vector<pair<int, int>> e[40000];
int dist[40000];
bool visit[40000];
priority_queue<pair<int, int>, vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
int n;

int findidx(int temp) {
	int cnt = 0;
	if (temp == 0)
	{
		return -1;
	}
	while ((temp & 1) == 0)
	{
		temp = (temp >> 1);
		cnt++;
	}
	return cnt;
}
void Dij() {
	int start = 0;
	int end = (1 << n) - 1;
	pq.push({ 0, start });
	for (int i = 0; i < 40000; i++)
	{
		dist[i] = 987654321;
	}
	dist[start] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (visit[node] == false)
		{
			visit[node] = true;
			for (int i = 0; i < e[node].size(); i++)
			{
				int nextnode = e[node][i].first;
				int nextcost = e[node][i].second;
				if (nextnode != end)
				{
					int minidx = findidx(nextnode & -nextnode);
					bool flag = true;
					for (int j = 0; j < n; j++)
					{
						if ((nextnode & (1 << j)) == 0 && v[j] != v[minidx])
						{
							flag = false;
						}
					}

					if (flag)
					{
						int temp = nextnode;
						while (v[findidx(temp & -temp)] == v[minidx])
						{
							temp = temp & (temp - 1);
						}
						minidx = findidx(temp & -temp);
					}
					nextcost += v[minidx];
					nextnode = (nextnode & ~(1 << minidx));
				}


				if (dist[nextnode] > dist[node] + nextcost)
				{
					dist[nextnode] = dist[node] + nextcost;
					pq.push({ dist[nextnode], nextnode });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	if (n == 1)
	{
		cout << v[0];
		return 0;
	}
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) == 0)
			{
				for (int k = 0; k < j; k++)
				{
					if ((i & (1 << k)) == 0 && v[j] != v[k])
					{
						int temp = (i | (1 << k) | (1 << j));
						e[i].push_back({ temp, v[j] });
					}
				}
			}
		}
	}
	Dij();
	if (dist[(1 << n) - 1] == 987654321)
	{
		cout << "-1\n";
	}
	else
	{
		cout << dist[(1 << n) - 1];
	}
}