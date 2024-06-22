#include <bits/stdc++.h>
#define mod 1000000007;
typedef long long ll;
using namespace std;

int n;
deque<pair<int, int>> d;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		d.push_back({num, i});
	}
	while (d.size() > 1)
	{
		int move = d.front().first;
		v.push_back(d.front().second);
		if (move > 0)
		{
			d.pop_front();
			for (int i = 0; i < move - 1; i++)
			{
				pair<int, int> temp = d.front();
				d.pop_front();
				d.push_back(temp);
			}
		}
		else
		{
			d.pop_front();
			for (int i = 0; i < -move; i++)
			{
				pair<int, int> temp = d.back();
				d.pop_back();
				d.push_front(temp);
			}
		}
	}
	v.push_back(d.front().second);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}