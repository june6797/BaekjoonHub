#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int parent[100001];
vector<pair<int, int>> x;
vector<pair<int, int>> y;
vector<pair<int, int>> z;
vector<pair<int, pair<int, int>>> v;

int Findparent(int a) {
	if (parent[a] == a)
	{
		return a;
	}
	else
	{
		return parent[a] = Findparent(parent[a]);
	}
}
void Unionfind(int a, int b) {
	a = Findparent(a);
	b = Findparent(b);
	if (a != b)
	{
		parent[b] = a;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a, i });
		y.push_back({ b, i });
		z.push_back({ c, i });
		parent[i] = i;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	for (int i = 0; i < N - 1; i++)
	{
		v.push_back({ x[i + 1].first - x[i].first, { x[i].second, x[i + 1].second} });
		v.push_back({ y[i + 1].first - y[i].first, { y[i].second, y[i + 1].second} });
		v.push_back({ z[i + 1].first - z[i].first, { z[i].second, z[i + 1].second} });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int a = v[i].second.first;
		int b = v[i].second.second;
		if (Findparent(a) != Findparent(b))
		{
			ans += v[i].first;
			Unionfind(a, b);
		}
	}
	cout << ans;
}