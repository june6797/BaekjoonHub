#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minpq;
priority_queue<int> maxpq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		if (minpq.size() >= maxpq.size())
		{
			maxpq.push(num);
		}
		else
		{
			minpq.push(num);
		}
		if (maxpq.size() > 0 && minpq.size() > 0)
		{
			if (maxpq.top() > minpq.top())
			{
				int maxt = maxpq.top();
				int mint = minpq.top();
				maxpq.pop();
				minpq.pop();
				maxpq.push(mint);
				minpq.push(maxt);
			}
		}
		cout << maxpq.top() << "\n";
	}

}