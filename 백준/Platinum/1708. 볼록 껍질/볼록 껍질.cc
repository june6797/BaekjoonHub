#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int ll;
const int INF = 1234567890;
using namespace std;

struct Point {
	ll x, y;
};

Point p[100001];

ll ccw(Point a, Point b, Point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - (a.x * c.y + c.x * b.y + b.x * a.y);
}
bool compare_y(Point a, Point b) {
	if (a.y != b.y)
	{
		return a.y < b.y;
	}
	else
	{
		return a.x < b.x;
	}
}

bool compare_ccw(Point a, Point b) {
	ll cc = ccw(p[0], a, b);
	if (cc != 0)
	{
		return cc > 0;
	}
	else
	{
		if (a.y != b.y)
		{
			return a.y < b.y;
		}
		else
		{
			return a.x < b.x;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + n, compare_y);
	sort(p + 1, p + n, compare_ccw);
	stack<Point> s;
	s.push(p[0]);
	s.push(p[1]);
	for (int i = 2; i < n; i++)
	{
		while (s.size() >= 2)
		{
			Point second = s.top();
			s.pop();
			Point first = s.top();
			if (ccw(first, second, p[i]) > 0)
			{
				s.push(second);
				break;
			}
		}
		s.push(p[i]);
	}
	cout << s.size();
}