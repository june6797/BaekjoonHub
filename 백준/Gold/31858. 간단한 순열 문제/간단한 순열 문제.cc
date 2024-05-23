#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <regex>
#include <stack>

#define mod 1000000007;
typedef long long int ll;

using namespace std;

stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, ans = 0;
	cin >> N;
	int first;
	cin >> first;
	s.push(first);
	for (int i = 0; i < N - 1; i++)
	{
		int num;
		cin >> num;
		ans++;
		while (s.size() >= 2 && s.top() < num)
		{
			s.pop();
			ans++;
		}
		if (s.top() < num)
		{
			s.pop();
			s.push(num);
		}
		else
		{
			s.push(num);
		}
	}
	cout << ans;
}