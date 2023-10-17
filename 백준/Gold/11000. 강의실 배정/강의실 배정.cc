#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back({ start, end });
	}
	sort(v.begin(), v.end());
	pq.push(0);
	for (int i = 0; i < N; i++)
	{
		if (v[i].first < pq.top())
		{
			pq.push(v[i].second);
		}
		else
		{
			pq.pop();
			pq.push(v[i].second);
		}
	}
	cout << pq.size();

}