#include <iostream>
#include <stack>
using namespace std;

int arr[100005];
stack <int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int ans = 0;
	s.push(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= N + 1; i++)
	{
		while (!s.empty() && arr[s.top()] > arr[i])
		{
			int h = arr[s.top()];
			s.pop();
			int l = i - s.top() - 1;
			ans = max(ans, h * l);
		}
		s.push(i);
	}

	cout << ans;

}