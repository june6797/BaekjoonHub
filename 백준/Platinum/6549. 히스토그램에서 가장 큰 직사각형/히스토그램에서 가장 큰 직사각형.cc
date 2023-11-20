#include <iostream>
#include <stack>
using namespace std;

long long int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	while (1)
	{
		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		stack <int> s;
		long long int ans = 0;
		s.push(0);
		for (int i = 1; i <= N; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i <= N + 1; i++)
		{
			while (!s.empty() && arr[s.top()] > arr[i])
			{
				long long int h = arr[s.top()];
				s.pop();
				long long int l = i - s.top() - 1;
				ans = max(ans, h * l);
			}
			s.push(i);
		}
		for (int i = 0; i < 100005; i++)
		{
			arr[i] = 0;
		}
		cout << ans << "\n";
	}


}