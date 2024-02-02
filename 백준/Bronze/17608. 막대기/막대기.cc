#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		while (!s.empty() && s.top() <= num)
		{
			s.pop();
		}
		s.push(num);

	}
	cout << s.size();
}