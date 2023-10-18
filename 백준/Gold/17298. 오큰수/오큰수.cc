#include <iostream>
#include <stack>
using namespace std;

stack <int> s;
int arr[1000001];
int ans[1000001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n; i >= 1; i--)
	{
		while (!s.empty() && s.top() <= arr[i])
		{
			s.pop();
		}

		if (s.empty())
		{
			ans[i] = -1;
		}
		else
		{
			ans[i] = s.top();
		}
		s.push(arr[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
}