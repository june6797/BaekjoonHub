#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;

int BFS(int a, int b) {
	q.push({ a, 1 });
	while (!q.empty())
	{
		long long int t = q.front().first;
		long long int ans = q.front().second;
		q.pop();
		if (t == b)
		{
			return ans;
		}
		if (2 * t <= b)
		{
			q.push({ 2 * t, ans + 1 });
		}
		if (10 * t + 1 <= b)
		{
			q.push({ 10 * t + 1, ans + 1 });
		}
	}
	return -1;
}

int main() {
	long long int a, b;
	cin >> a >> b;
	cout << BFS(a, b);
}
