#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	long long int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int k, same = 1;
		cin >> k;
		while (!s.empty() && s.top().first < k)
		{
			ans += s.top().second;
			s.pop();
		}
		if (!s.empty())
		{
			if (s.top().first == k)
			{
				ans += s.top().second;
				same = s.top().second + 1;
				if (s.size() > 1)
				{
					ans++;
				}
				s.pop();
			}
			else
			{
				ans++;
			}
		}
		s.push({ k, same });
	}
	cout << ans;
}