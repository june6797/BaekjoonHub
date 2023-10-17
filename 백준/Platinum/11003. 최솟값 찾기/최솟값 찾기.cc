#include <iostream>
#include <deque>
using namespace std;
deque<pair<int, int>> d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, L;
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;

		while (!d.empty() && d.back().second > num)
		{
			d.pop_back();
		}
		d.push_back({ i, num });

		if (d.front().first < i - L + 1)
		{
			d.pop_front();
		}
		cout << d.front().second << " ";
	}
}