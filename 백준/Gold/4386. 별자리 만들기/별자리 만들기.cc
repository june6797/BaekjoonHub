#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
using namespace std;

vector <pair<double, pair<double, double>>> v;
vector<pair<int, pair<double, double>>> dot;
int parent[10001];

double distance(double x, double y) {
	return sqrt(x * x + y * y);
}

int Find(int x) {
	if (x != parent[x])
	{
		return parent[x] = Find(parent[x]);
	}
	else
	{
		return x;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y)
	{
		parent[y] = x;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double a, b;
		cin >> a >> b;
		dot.push_back({ i, { a, b } });
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double temp = distance(dot[i].second.first - dot[j].second.first,
				dot[i].second.second - dot[j].second.second);
			v.push_back({ temp, {dot[i].first, dot[j].first} });
		}
		sort(v.begin(), v.end());
	}
	double ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].second.first;
		int y = v[i].second.second;
		double d = v[i].first;
		if (Find(x) != Find(y))
		{
			Union(x, y);
			ans += d;
		}
	}
	cout << ans;
}