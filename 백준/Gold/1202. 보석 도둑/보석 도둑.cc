#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> pq2;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	long long int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;
		pq.push({ M, V });
	}
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < K; i++)
	{
		while (!pq.empty() && pq.top().first <= v[i])
		{
			pq2.push(pq.top().second);
			pq.pop();
		}
		if (!pq2.empty())
		{
			ans += pq2.top();
			pq2.pop();
		}
	}
	cout << ans;
}