#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> node[500005];
int visit[500005];
priority_queue<pair<int, int>, vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int sum = 0;
	node[0].push_back(1);
	node[1].push_back(0);

	visit[0] = 1;
	pq.push({ 0, 0 });
	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;
		for (int j = 0; j < A - 1; j++)
		{
			int a, b;
			cin >> a >> b;
			node[sum + a].push_back(sum + b);
			node[sum + b].push_back(sum + a);

		}

		while (!pq.empty())
		{
			int depth = pq.top().first;
			int nodenum = pq.top().second;
			if (node[nodenum].size() == 1)
			{
				if (nodenum != 0) {
					if (ans < depth)
					{
						ans = depth;
					}
					break;
				}
			}
			pq.pop();
			for (int i = 0; i < node[nodenum].size(); i++)
			{
				if (visit[node[nodenum][i]] == 0)
				{
					pq.push({ depth + 1, node[nodenum][i]});
					visit[node[nodenum][i]] = 1;
				}
			}
		}

		sum += A;

		//cout << pq.size() << "s\n";
		//cout << pq.top().first << " " << pq.top().second << "fs\n";
		if (i != N - 1)
		{
			node[pq.top().second].push_back(sum + 1);

			node[sum + 1].push_back(pq.top().second);
		}
	}
	while (!pq.empty())
	{
		int depth = pq.top().first;
		int nodenum = pq.top().second;
		
		if (ans < depth)
		{
			ans = depth;
		}
		
		pq.pop();
		for (int i = 0; i < node[nodenum].size(); i++)
		{
			if (visit[node[nodenum][i]] == 0)
			{
				pq.push({ depth + 1, node[nodenum][i] });
				visit[node[nodenum][i]] = 1;
			}
		}
	}
	cout << ans;
}