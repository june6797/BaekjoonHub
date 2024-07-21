#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		if (s > e)
		{
			v.push_back({ s, e });
		}
		else
		{
			v.push_back({ e, s });
		}
	}
	int d;
	cin >> d;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		int end = v[i].first;
		int start = v[i].second;
		if (end - start <= d)
		{
			pq.push(start);
			while (!pq.empty())
			{
				if (pq.top() + d >= end)
				{
					ans = max(ans, (int)pq.size());
					break;
				}
				else
				{
					pq.pop();
				}
			}
		}
	}
	cout << ans;
}