#include <iostream>
#include <stack>
using namespace std;

int arr[100001];
stack <pair<int, long long int>> s;
int main() {
	int N;
	long long int ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	s.push({ 0,0 });

	for (int i = 1; i <= N; i++)
	{
		while (s.top().second > arr[i])
		{
			long long int h = s.top().second;
			long long int b = i - 1;
			s.pop();
			long long int a = s.top().first;
			ans = max(ans, h * (b - a));
		}
		s.push({ i, arr[i] });
	}
	while (s.size() > 1)
	{
		long long int h = s.top().second;
		long long int b = N;
		s.pop();
		long long int a = s.top().first;
		ans = max(ans, h * (b - a));
	}
	cout << ans;
}