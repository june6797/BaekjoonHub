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
typedef long long int ll;
using namespace std;

deque<int> d;
int state, bcnt, wcnt;

void drop() {
	if (state == 1)
	{
		if (!d.empty())
		{
			while (!d.empty() && d.front() == 0)
			{
				bcnt--;
				d.pop_front();
			}
		}
	}
	else if (state == 3) {
		if (!d.empty())
		{
			while (!d.empty() && d.back() == 0)
			{
				bcnt--;
				d.pop_back();
			}
		}
	}
}

void dpush(int temp) {
	if (state == 1)
	{
		d.push_back(temp);
		drop();
	}
	else if (state == 3) {
		d.push_back(temp);
		drop();
	}
	else
	{
		d.push_back(temp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int Q;
	cin >> Q;
	while (Q--)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			char a;
			cin >> a;
			if (a == 'b')
			{
				bcnt++;
				dpush(0);
			}
			else if (a == 'w')
			{
				wcnt++;
				dpush(1);
			}
		}
		else if (s == "pop")
		{
			if (state == 1)
			{
				if (!d.empty())
				{
					wcnt--;
					d.pop_front();
				}
				drop();
			}
			else if (state == 3)
			{
				if (!d.empty())
				{
					if (d.front() == 0)
					{
						bcnt--;
					}
					else
					{
						wcnt--;
					}
					d.pop_front();
				}
			}
			else {
				if (!d.empty())
				{
					if (d.front() == 0)
					{
						bcnt--;
					}
					else
					{
						wcnt--;
					}
					d.pop_front();
				}
			}
		}
		else if (s == "rotate")
		{

			char a;
			cin >> a;
			if (a == 'l')
			{
				state = (state + 3) % 4;
			}
			else if (a == 'r')
			{
				state = (state + 1) % 4;
			}
			drop();
		}
		else if (s == "count")
		{

			char a;
			cin >> a;
			if (a == 'b')
			{
				cout << bcnt << "\n";
			}
			else if (a == 'w')
			{
				cout << wcnt << "\n";
			}
		}
	}
}