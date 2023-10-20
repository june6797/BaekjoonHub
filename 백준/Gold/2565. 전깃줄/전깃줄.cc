#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;
int arr[501];
int ans[501];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		pq.push({ a, b });
	}
	for (int i = 1; i <= N; i++)
	{
		arr[i] = pq.top().second;
		pq.pop();
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] < arr[i])
			{
				ans[i] = max(ans[i], ans[j] + 1);
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, ans[i]);
	}
	cout << N - answer;
}