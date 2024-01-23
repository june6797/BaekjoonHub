#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	while (q.size() > 1)
	{
		cout << q.front() << " ";
		q.pop();
		int t = q.front();
		q.push(t);
		q.pop();
	}
	cout << q.front();
}