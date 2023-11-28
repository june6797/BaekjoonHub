#include <iostream>
#include <queue>
#include <map>
using namespace std;

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq;
map<int, int> m;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int k;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			char a;
			cin >> a;
			if (a == 'I')
			{
				int num;
				cin >> num;
				maxpq.push(num);
				minpq.push(num);
				m[num]++;
			}
			else if (a == 'D')
			{
				int num;
				cin >> num;
				if (num == 1)
				{
					if (!maxpq.empty())
					{
						m[maxpq.top()]--;
						maxpq.pop();
					}
					while (!maxpq.empty() &&
						m[maxpq.top()] == 0)
					{
						maxpq.pop();
					}
					while (!minpq.empty() &&
						m[minpq.top()] == 0)
					{
						minpq.pop();
					}
				}
				else
				{
					if (!minpq.empty())
					{
						m[minpq.top()]--;
						minpq.pop();
					}
					while (!maxpq.empty() &&
						m[maxpq.top()] == 0)
					{
						maxpq.pop();
					}
					while (!minpq.empty() &&
						m[minpq.top()] == 0)
					{
						minpq.pop();
					}
				}
			}
		}
		if (maxpq.empty() || minpq.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << maxpq.top() << " " << minpq.top() << "\n";
		}
		while (!maxpq.empty()) {
			maxpq.pop();
		}
		while (!minpq.empty()) {
			minpq.pop();
		}
		m.clear();
	}
}