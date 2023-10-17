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
		if (d.empty())
		{
			d.push_back({ i, num });
		}
		else
		{
			while (d.back().second > num)
			{
				d.pop_back();
				if (d.empty())
				{
					break;
				}
			}
			d.push_back({ i, num });
		}
		while (d.front().first < i - L + 1)
		{
			d.pop_front();
		}
		cout << d.front().second << " ";
	}
}